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
