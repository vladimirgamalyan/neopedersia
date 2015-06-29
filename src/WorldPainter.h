#pragma once

#include "Texture.h"
#include "Vec2.h"

class WorldPainter
{
public:
    virtual void setOffset(const Vec2& offset) = 0;
    virtual void draw(const Vec2& pos, const Texture & picture) const = 0;
};
