#include "Cannonball.h"
#include <cmath>
#include "../World.h"

Cannonball::Cannonball(const Vec2 &pos, WorldObject *target, int damage)
{
    setPos(pos);
    posXf = pos.x;
    posYf = pos.y;
    this->target = target;
    this->damage = damage;
}

void Cannonball::update()
{
    double targetX = static_cast< double >( target->getPos().x );
    double targetY = static_cast< double >( target->getPos().y );

    double step = PIXEL_PER_FRAME;

    // tangent.
    double a = targetX - posXf;
    double b = targetY - posYf;

    // hypotenuse or distance to target.
    double c = std::sqrt((a * a + 0.0000001) + (b * b + 0.0000001)) + 0.0000001;

    // limit to distance.
    if (step > c)
        step = c;

    // normalize vector direction.
    double an = a / c;
    double bn = b / c;

    // mult by step.
    an *= step;
    bn *= step;

    posXf += an;
    posYf += bn;

    setPos(Vec2(static_cast< int >(posXf), static_cast< int >(posYf)));

    //////////////////////////////////////////////////////////////////////////

    if (c < PIXEL_PER_FRAME)
    {
        // target is reached.
        target->hit(damage);
        world->removeWorldObject(this);
        return;
    }

    if (target->isDead())
    {
        world->removeWorldObject(this);
        return;
    }
}

void Cannonball::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/cannon/cannonball.png");
}
