#include "Wall.h"
#include "../World.h"

void Wall::update()
{

}

void Wall::render(const WorldPainter &worldPainter) const
{
    bool leftLink = (world->getBuilding((pos / Config::World::CELL_SIZE) + Vec2(-1, 0)) == WorldObjectId::Wall);
    bool rightLink = (world->getBuilding((pos / Config::World::CELL_SIZE) + Vec2(0, -1)) == WorldObjectId::Wall);

    if (leftLink)
    {
        if (rightLink)
            worldPainter.draw(pos, "assets/walls/4.png");
        else
            worldPainter.draw(pos, "assets/walls/2.png");
    }
    else
    {
        if (rightLink)
            worldPainter.draw(pos, "assets/walls/3.png");
        else
            worldPainter.draw(pos, "assets/walls/1.png");
    }
}

Vec2 Wall::getDim() const
{
    return Vec2(1, 1);
}

WorldObjectId Wall::getId() const
{
    return WorldObjectId::Wall;
}
