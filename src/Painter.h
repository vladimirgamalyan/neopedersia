#pragma once

#include "Texture.h"
#include "Point.h"

class Painter
{
public:
    virtual void draw(const Point& pos, const Texture & picture) const = 0;
};
