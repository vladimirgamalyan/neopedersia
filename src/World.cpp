#include "World.h"

void World::update()
{
    ground.update();
}

void World::render()
{
    ground.render(worldPainter);
}
