#pragma once

#include "Texture.h"
#include "Point.h"
#include "Size.h"

class Painter
{
public:
    virtual void draw(const Point& pos, const Texture& picture) const = 0;
    virtual Size getTextureSize(const Texture& picture) const = 0;
};
