#pragma once

#include "Ground.h"
#include "WorldPainterImpl.h"

class World
{
public:
    World(Painter& painter) : worldPainter(painter) {}
    void update();
    void render();

private:
    WorldPainterImpl worldPainter;
    Ground ground;
};
