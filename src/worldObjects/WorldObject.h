#pragma once
#include "../WorldPainter.h"

class World;

class WorldObject
{
public:
    void assignWorld(World* world);
    virtual void update() = 0;
    virtual void render(const WorldPainter& worldPainter) const = 0;
    virtual void setPos(const Point& pos);
    Point getPos() const;

protected:
    World* world;
    Point pos;
};
