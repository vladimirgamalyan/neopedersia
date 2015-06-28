#pragma once
#include "WorldPainter.h"

class WorldObject
{
public:
    virtual void update() = 0;
    virtual void render(const WorldPainter& worldPainter) const = 0;
};
