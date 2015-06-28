#include "WorldObject.h"

void WorldObject::setPos(const Point &pos)
{
    this->pos = pos;
}

Point WorldObject::getPos() const
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

Size WorldObject::getDim() const
{
    return Size();
}
