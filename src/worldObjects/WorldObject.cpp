#include "WorldObject.h"
#include "WorldObjectId.h"

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
