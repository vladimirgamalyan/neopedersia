#pragma once

#include "Ground.h"
#include "WorldPainterImpl.h"
#include "worldObjects/WorldObject.h"
#include "Rect.h"
#include <list>
#include <vector>
#include "PathFinder.h"

class World
{
public:
    World(Painter& painter) : worldPainter(painter) {}
    void fill();
    void update();
    void render();
    void moveMap(const Vec2& offset);
    int find(const Point& from, const Point& to, std::vector<Point>& path);

private:
    static const int CELL_SIZE = 8;

    void updatePathFinderMap();
    void putWallRect(const Rect &rect);
    void putWallLine(Point from, const Vec2& direction, int len);
    void addWorldObject(WorldObject* worldObject, const Point& pos);
    void addWorldObject(WorldObject* worldObject);
    void removeWallByPos(const Point& pos);

    WorldPainterImpl worldPainter;
    Ground ground;
    Vec2 offset;
    PathFinder pathFinder;

    //TODO: Delete items.
    std::list<WorldObject*> items;
};
