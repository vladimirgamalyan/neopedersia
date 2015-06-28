#pragma once

#include "Ground.h"
#include "WorldPainterImpl.h"

class World
{
public:
    World(Painter& painter) : worldPainter(painter) {}
    void update();
    void render();
    void moveMap(const Vec2& offset);

private:
    WorldPainterImpl worldPainter;
    Ground ground;
    Vec2 offset;
};
