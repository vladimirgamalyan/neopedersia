#pragma once

#include <vector>
#include "WorldObject.h"

class Pony : public WorldObject
{
public:
    Pony();
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;
    virtual bool isTargetable() const;

private:
    enum States
    {
        Still,
        Running,
        Attack,
        Pass
    };
    int state;
    WorldObject* target;
    std::vector<Vec2> path;
    int step;
    bool directionRight;
};
