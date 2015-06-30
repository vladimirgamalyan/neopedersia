#include "WorldObject.h"
#include "WorldObjectId.h"
#include <iostream>

void WorldObject::setPos(const Vec2 &pos)
{
    this->pos = pos;
}

Vec2 WorldObject::getPos() const
{
    return pos;
}

void WorldObject::assignWorld(World *world)
{
    this->world = world;
}

bool WorldObject::isDead() const
{
    return hp <= 0;
}

Vec2 WorldObject::getDim() const
{
    return Vec2();
}

WorldObjectId WorldObject::getId() const
{
    return WorldObjectId::Generic;
}

bool WorldObject::isTargetable() const
{
    return false;
}

void WorldObject::hit(int damage)
{
    if (hp < damage)
        hp = 0;
    else
        hp -= damage;
}

void WorldObject::renderHealth(const WorldPainter& worldPainter) const
{
    if (!hp)
        return;

    if (hp == getFullHp())
        return;

    const int BAR_W = 48;
    const int BAR_H = 4;

    float healthPercent = static_cast< float >( hp ) / static_cast< float >( getFullHp() );

    Rect r(BAR_W, BAR_H);
    r += Vec2(-BAR_W / 2, -60);

    Rect rh(r.x, r.y, static_cast<int>(static_cast<float>(BAR_W) * healthPercent), BAR_H);
    r.extend(1);

    worldPainter.fillRectEx(pos, r, Color::WHITE);

    if (healthPercent < 0.3f)
        worldPainter.fillRectEx(pos, rh, Color::RED);
    else
        worldPainter.fillRectEx(pos, rh, Color::GREEN);
}

int WorldObject::getFullHp() const
{
    return 100;
}
