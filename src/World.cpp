#include "World.h"
#include "worldObjects/Wall.h"

void World::update()
{
    ground.update();
}

void World::render()
{
    ground.render(worldPainter);

    for (std::list<WorldObject*>::const_iterator it = items.begin(); it != items.end(); ++it)
        (*it)->render(worldPainter);
}

void World::moveMap(const Vec2 &offset)
{
    this->offset += offset;
    worldPainter.setOffset(this->offset);
}

void World::fill()
{
    putWallRect(Rect(0, 0, 28, 28));
    putWallRect(Rect(4, 4, 24, 24));
    putWallRect(Rect(10, 10, 12, 12));
}

void World::putWallRect(const Rect &rect)
{
    putWallLine(Point(rect.x, rect.y), Vec2(1, 0), rect.w);
    putWallLine(Point(rect.x, rect.y + rect.h - 1), Vec2(1, 0), rect.w);
    putWallLine(Point(rect.x, rect.y), Vec2(0, 1), rect.h);
    putWallLine(Point(rect.x + rect.w - 1, rect.y), Vec2(0, 1), rect.h);
}

void World::putWallLine(Point from, const Vec2 &direction, int len)
{
    while ( len > 0 )
    {
        Wall* wall = new Wall;
        addWorldObject(wall, Point(from.x * 8, from.y * 8));
        from.x += direction.x;
        from.y += direction.y;
        len--;
    }
}

void World::addWorldObject(WorldObject *worldObject, const Point &pos)
{
    worldObject->setPos(pos);
    addWorldObject(worldObject);
}

void World::addWorldObject(WorldObject *worldObject)
{
    worldObject->assignWorld(this);
    items.push_back(worldObject);
}
