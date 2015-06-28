#pragma once

#include "WorldObject.h"

class Ground : public WorldObject
{
public:
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;

private:

};
