#include "World.h"
#include "worldObjects/Wall.h"
#include "worldObjects/Pony.h"
#include "worldObjects/TownHall.h"
#include "worldObjects/Bojarski.h"

void World::update()
{
    updatePathFinderMap();
    ground.update();

    for (std::list<WorldObject *>::const_iterator it = items.begin(); it != items.end(); ++it)
        (*it)->update();
}

void World::render()
{
    ground.render(worldPainter);

    for (std::list<WorldObject *>::const_iterator it = items.begin(); it != items.end(); ++it)
        (*it)->render(worldPainter);
}

void World::moveMap(const Vec2 &offset)
{
    this->offset += offset;
    worldPainter.setOffset(this->offset);
}

void World::fill()
{
    //Wall* wall = new Wall;
    //addWorldObject(wall, Point(0, 0));
    putWallRect(Rect(0, 0, 28, 28));
    putWallRect(Rect(4, 4, 24, 24));
    putWallRect(Rect(10, 10, 12, 12));

    for (int i = 0; i < 16; ++i)
        addWorldObject(new Pony, Point(1, 1));
    addWorldObject(new TownHall, Point(14, 14));

    addWorldObject(new Bojarski, Point(16, 12));
}

void World::putWallRect(const Rect &rect)
{
    putWallLine(Point(rect.x, rect.y), Vec2(1, 0), rect.w);
    putWallLine(Point(rect.x, rect.y + rect.h - 1), Vec2(1, 0), rect.w);
    putWallLine(Point(rect.x, rect.y), Vec2(0, 1), rect.h);
    putWallLine(Point(rect.x + rect.w - 1, rect.y), Vec2(0, 1), rect.h);
    removeWallByPos(Point(4, 10));
    removeWallByPos(Point(21, 12));
}

void World::removeWallByPos(const Point &pos)
{
    for (std::list<WorldObject *>::iterator it = items.begin(); it != items.end(); ++it)
    {
        if ((pos * CELL_SIZE) == (*it)->getPos())
        {
            delete *it;
            items.erase(it);
            break;
        }
    }
}

void World::putWallLine(Point from, const Vec2 &direction, int len)
{
    while (len > 0)
    {
        Wall *wall = new Wall;
        addWorldObject(wall, from);
        from.x += direction.x;
        from.y += direction.y;
        len--;
    }
}

void World::addWorldObject(WorldObject *worldObject, const Point &pos)
{
    worldObject->setPos(pos * CELL_SIZE);
    addWorldObject(worldObject);
}

void World::addWorldObject(WorldObject *worldObject)
{
    worldObject->assignWorld(this);
    items.push_back(worldObject);
}

int World::find(const Point &from, const Point &to, std::vector<Point> &path)
{
    return pathFinder.find(from / CELL_SIZE, to / CELL_SIZE, path);
}

void World::updatePathFinderMap()
{
    for (int col = 0; col < PathFinder::MAP_WIDTH; ++col)
        for (int row = 0; row < PathFinder::MAP_HEIGHT; ++row)
            pathFinder.cells[col][row] = 0;

    for (std::list<WorldObject*>::iterator it = items.begin(); it != items.end(); ++it)
    {
        WorldObject *worldObject = *it;
        Size size = worldObject->getDim();

        if (!size.isZero())
        {
            Point p = worldObject->getPos() / CELL_SIZE;

            for (int col = 0; col < size.w; ++col)
                for (int row = 0; row < size.h; ++row)
                    pathFinder.cells[col + p.x][row + p.y] = 1;
        }
    }
}
