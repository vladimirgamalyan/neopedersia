#pragma once

#include "Point.h"
#include "Picture.h"

class WorldPainter
{
public:
    virtual void draw(const Point& pos, const Picture& picture) const = 0;
};
