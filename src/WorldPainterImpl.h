#pragma once

#include "WorldPainter.h"
#include "Painter.h"

class WorldPainterImpl : public WorldPainter
{
public:
    WorldPainterImpl(Painter& painter) : painter(painter) {}
    virtual void draw(const Point& pos, const Texture & picture) const;

private:
    Painter& painter;
};
