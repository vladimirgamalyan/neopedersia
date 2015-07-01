#pragma once

#include "WorldObject.h"

class MachinegunBullet : public WorldObject
{
public:
    MachinegunBullet(const Vec2& pos, WorldObject *target, int damage);
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;

public:
    WorldObject* target = nullptr;
    double posXf;
    double posYf;
    int damage;

private:
    static const int PIXEL_PER_FRAME = 2;
};
