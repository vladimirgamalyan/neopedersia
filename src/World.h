#pragma once

#include "Ground.h"
#include "WorldPainterImpl.h"
#include "worldObjects/WorldObject.h"
#include "Rect.h"
#include <list>

class World
{
public:
    World(Painter& painter) : worldPainter(painter) {}
    void fill();
    void update();
    void render();
    void moveMap(const Vec2& offset);

private:
    void putWallRect(const Rect &rect);
    void putWallLine(Point from, const Vec2& direction, int len);
    void addWorldObject(WorldObject* worldObject, const Point& pos);
    void addWorldObject(WorldObject* worldObject);

    WorldPainterImpl worldPainter;
    Ground ground;
    Vec2 offset;

    //TODO: Delete items.
    std::list<WorldObject*> items;
};
