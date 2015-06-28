#pragma once

class Point
{
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& other) const
    {
        return ((x == other.x) && (y == other.y));
    }
    bool operator!=(const Point& other) const
    {
        return ((x != other.x) || (y != other.y));
    }

    Point operator*(int value) const
    {
        return Point(x * value, y * value);
    }

    Point& operator*=(int value)
    {
        x *= value;
        y *= value;
        return *this;
    }

    Point operator/(int value) const
    {
        return Point(x / value, y / value);
    }

    Point& operator/=(int value)
    {
        x /= value;
        y /= value;
        return *this;
    }

    int x = 0;
    int y = 0;

private:

};
