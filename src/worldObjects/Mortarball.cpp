#include "Mortarball.h"
#include <cmath>
#include "../World.h"

Mortarball::Mortarball(const Vec2 &pos, const Vec2& target, int damage)
{
    setPos(pos);
    posXf = pos.x;
    posYf = pos.y;
    this->target = target;
    this->damage = damage;
}

void Mortarball::update()
{
    double targetX = static_cast< double >( target.x );
    double targetY = static_cast< double >( target.y );

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
        world->massiveDamage(target, DAMAGE_RANGE, damage);
        world->removeWorldObject(this);
        return;
    }
}

void Mortarball::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/mortar/mortarball.png");
}
