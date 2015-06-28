#pragma once

#include "Texture.h"
#include "Point.h"
#include "Vec2.h"

class WorldPainter
{
public:
    virtual void setOffset(const Vec2& offset) = 0;
    virtual void draw(const Point& pos, const Texture & picture) const = 0;
};
