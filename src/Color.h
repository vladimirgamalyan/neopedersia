#pragma once

#include <cstdint>

class Color
{
public:
    static const uint32_t WHITE = 0xFFFFFFFF;
    static const uint32_t BLACK = 0xFF000000;

    static const uint32_t GREEN = 0xFF00FF00;
    static const uint32_t RED = 0xFF0000FF;

    Color() : r(0), g(0), b(0), a(0) {}
    Color(uint32_t rgba)
    {
        r = static_cast< uint8_t >((rgba >> 0 ) & 0xFF);
        g = static_cast< uint8_t >((rgba >> 8 ) & 0xFF);
        b = static_cast< uint8_t >((rgba >> 16 ) & 0xFF);
        a = static_cast< uint8_t >((rgba >> 24 ) & 0xFF);
    }
    uint8_t r, g, b, a;
};
