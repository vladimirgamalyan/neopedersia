#pragma once

class Rect
{
public:
    Rect() : x(0), y(0), w(0), h(0) {}
    Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    int x;
    int y;
    int w;
    int h;
};
