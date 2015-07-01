#include "MachinegunBullet.h"
#include <cmath>
#include "../World.h"

MachinegunBullet::MachinegunBullet(const Vec2 &pos, WorldObject *target, int damage)
{
    setPos(pos);
    posXf = pos.x;
    posYf = pos.y;
    this->target = target;
    this->damage = damage;
}

void MachinegunBullet::update()
{
    double targetX = static_cast< double >( target->getPos().x );
    double targetY = static_cast< double >( target->getPos().y );

    double step = PIXEL_PER_FRAME;

    // Находим тангенс угла.
    double a = targetX - posXf;
    double b = targetY - posYf;

    // Гипотенуза - она же расстояние до цели.
    double c = std::sqrt((a * a + 0.0000001) + (b * b + 0.0000001)) + 0.0000001;

    // Чтобы не перелететь ненароком цель.
    if (step > c)
        step = c;

    // Нормализуем вектор направления.
    double an = a / c;
    double bn = b / c;

    // Умножаем на скорость.
    an *= step;
    bn *= step;

    posXf += an;
    posYf += bn;

    setPos(Vec2(static_cast< int >(posXf), static_cast< int >(posYf)));

    //////////////////////////////////////////////////////////////////////////

    if (c < PIXEL_PER_FRAME)
    {
        // Добрались до цели  - наносим ущерб и удаляем объект.
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

void MachinegunBullet::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/machinegun/machinegunBullet.png");
}
