#pragma once

class Vec2
{
public:
    Vec2() : x(0), y(0) {}
    Vec2(int x, int y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& other) const
    {
        return Vec2(x + other.x, y + other.y);
    }
    Vec2 operator-(const Vec2& other) const
    {
        return Vec2(x - other.x, y - other.y);
    }
    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    bool operator==(const Vec2& other) const
    {
        return ((x == other.x) && (y == other.y));
    }
    bool operator!=(const Vec2& other) const
    {
        return ((x != other.x) || (y != other.y));
    }

    Vec2 operator*(int value) const
    {
        return Vec2(x * value, y * value);
    }

    Vec2& operator*=(int value)
    {
        x *= value;
        y *= value;
        return *this;
    }

    Vec2 operator/(int value) const
    {
        return Vec2(x / value, y / value);
    }

    Vec2& operator/=(int value)
    {
        x /= value;
        y /= value;
        return *this;
    }
    bool isZero() const
    {
        return (x == 0) && (y == 0);
    }
    int x;
    int y;
};
