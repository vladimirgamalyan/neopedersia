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

    worldPainter.drawQueue();
}

void World::moveMap(const Vec2 &offset)
{
    this->offset += offset;
    worldPainter.setOffset(this->offset);
}

void World::fill()
{
    //addWorldObject(new Wall, Vec2(0, Config::World::HEIGHT_CELL));
    putWallRect(Rect(0, 0, Config::World::WIDTH_CELL, Config::World::HEIGHT_CELL));
    putWallRect(Rect(4, 4, 24, 24));
    putWallRect(Rect(10, 10, 12, 12));

    for (int i = 0; i < 16; ++i)
        addWorldObject(new Pony, Vec2(1, 1));
    addWorldObject(new TownHall, Vec2(14, 14));

    addWorldObject(new Bojarski, Vec2(16, 12));
}

void World::putWallRect(const Rect &rect)
{
    putWallLine(Vec2(rect.x, rect.y), Vec2(1, 0), rect.w);
    putWallLine(Vec2(rect.x, rect.y + rect.h - 1), Vec2(1, 0), rect.w);
    putWallLine(Vec2(rect.x, rect.y), Vec2(0, 1), rect.h);
    putWallLine(Vec2(rect.x + rect.w - 1, rect.y), Vec2(0, 1), rect.h);
    removeWallByPos(Vec2(4, 10));
    removeWallByPos(Vec2(21, 12));
}

void World::removeWallByPos(const Vec2 &pos)
{
    for (std::list<WorldObject *>::iterator it = items.begin(); it != items.end(); ++it)
    {
        if ((pos * Config::World::CELL_SIZE) == (*it)->getPos())
        {
            delete *it;
            items.erase(it);
            break;
        }
    }
}

void World::putWallLine(Vec2 from, const Vec2 &direction, int len)
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

void World::addWorldObject(WorldObject *worldObject, const Vec2 &pos)
{
    worldObject->setPos(pos * Config::World::CELL_SIZE);
    addWorldObject(worldObject);
}

void World::addWorldObject(WorldObject *worldObject)
{
    worldObject->assignWorld(this);
    items.push_back(worldObject);
}

int World::find(const Vec2 &from, const Vec2 &to, std::vector<Vec2> &path)
{
    return pathFinder.find(from / Config::World::CELL_SIZE, to / Config::World::CELL_SIZE, path);
}

void World::updatePathFinderMap()
{
    for (int col = 0; col < Config::World::WIDTH_CELL; ++col)
        for (int row = 0; row < Config::World::WIDTH_CELL; ++row)
            pathFinder.cells[col][row] = WorldObjectId::Empty;

    for (std::list<WorldObject*>::iterator it = items.begin(); it != items.end(); ++it)
    {
        WorldObject *worldObject = *it;
        Vec2 size = worldObject->getDim();

        if (!size.isZero())
        {
            Vec2 p = worldObject->getPos() / Config::World::CELL_SIZE;
            WorldObjectId id = worldObject->getId();

            for (int col = 0; col < size.x; ++col)
                for (int row = 0; row < size.y; ++row)
                    pathFinder.cells[col + p.x][row + p.y] = id;
        }
    }
}

void World::alignToWindowCenter(const Vec2& windowSize)
{
    Vec2 windowCenter = windowSize / 2;
    Vec2 worldSize(Config::World::WIDTH, Config::World::HEIGHT);
    Vec2 worldCenter = worldSize / 2;
    Vec2 worldCenterScr = worldPainter.worldToScreen(worldCenter);
    Vec2 offset = windowCenter - worldCenterScr;
    this->offset = offset;
    worldPainter.setOffset(this->offset);
}

WorldObjectId World::getBuilding(const Vec2 &pos) const
{
    if (!Rect(Config::World::WIDTH_CELL, Config::World::HEIGHT_CELL).contains(pos))
        return WorldObjectId::Empty;
    return pathFinder.cells[pos.x][pos.y];
}
