#include "Vec2.h"
#include <cmath>

double Vec2::distance(const Vec2 &other) const
{
    Vec2 d = *this - other;
    return std::sqrt(d.x * d.x + d.y * d.y);
}
