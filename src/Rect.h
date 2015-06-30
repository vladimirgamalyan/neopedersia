#pragma once

#include "Vec2.h"

class Rect
{
public:
    Rect() : x(0), y(0), w(0), h(0) {}
    Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    Rect(int w, int h) : x(0), y(0), w(w), h(h) {}
    Rect(const Vec2& size) : x(0), y(0), w(size.x), h(size.y) {}

    Vec2 pos() const
    {
        return Vec2(x, y);
    }
    Vec2 size() const
    {
        return Vec2(w, h);
    }


    int left() const
    {
        return x;
    }
    int right() const
    {
        return x + w - 1;
    }
    int top() const
    {
        return y;
    }
    int bottom() const
    {
        return y + h - 1;
    }

    Vec2 topLeft() const
    {
        return Vec2(left(), top());
    }
    Vec2 topRight() const
    {
        return Vec2(right(), top());
    }
    Vec2 bottomLeft() const
    {
        return Vec2(left(), bottom());
    }
    Vec2 bottomRight() const
    {
        return Vec2(right(), bottom());
    }

    bool contains(const Vec2& point) const
    {
        return point.x >= x && point.y >= y && point.x <= right() && point.y <= bottom();
    }

    int x, y, w, h;
};
