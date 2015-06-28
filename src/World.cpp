#include "World.h"

void World::update()
{
    ground.update();
}

void World::render()
{
    ground.render(worldPainter);
}

void World::moveMap(const Vec2 &offset)
{
    this->offset += offset;
    worldPainter.setOffset(this->offset);
}
