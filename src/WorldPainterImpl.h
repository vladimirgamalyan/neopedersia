#pragma once

#include "WorldPainter.h"
#include "Painter.h"

class WorldPainterImpl : public WorldPainter
{
public:
    WorldPainterImpl(Painter& painter) : painter(painter) {}
    virtual void setOffset(const Vec2& offset);
    virtual void draw(const Vec2& pos, const Texture & picture) const;

private:
    Painter& painter;
    Vec2 offset;
};
