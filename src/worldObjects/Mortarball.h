#pragma once

#include "WorldObject.h"

class Mortarball : public WorldObject
{
public:
    Mortarball(const Vec2& pos, const Vec2& target, int damage);
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;

public:
    Vec2 target;
    double posXf;
    double posYf;
    int damage;

private:
    static const int PIXEL_PER_FRAME = 1;
    static const int DAMAGE_RANGE = 30;
};
