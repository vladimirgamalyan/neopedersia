#pragma once

class Size
{
public:
    Size() : w(0), h(0) {}
    Size(int w, int h) : w(w), h(h) {}
    bool isZero() const
    {
        return (w == 0) && (h == 0);
    }
    int w;
    int h;
};
