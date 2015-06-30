#include <iostream>
#include "Cannon.h"
#include "Cannonball.h"
#include "../World.h"

Cannon::Cannon()
{
    state = State::STILL;
}

void Cannon::update()
{
    switch (state)
    {
        case State::STILL:
            updateStill();
            break;
        case State::COOLDOWN:
            updateCoolDown();
            break;
    }
}

void Cannon::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/cannon/cannon.png");
}

Vec2 Cannon::getDim() const
{
    return Vec2(2, 2);
}

void Cannon::updateStill()
{
    target = world->getNearestTarget(pos, getRange());
    if (target)
    {
        shot(target);
        state = State::COOLDOWN;
        cooldown = getCooldown();
    }
}

void Cannon::shot(WorldObject *worldObject)
{
    world->addWorldObject(new Cannonball(pos, worldObject, getDamage()), pos);
}

void Cannon::updateCoolDown()
{
    if (cooldown)
        cooldown--;
    else
        state = State::STILL;
}
