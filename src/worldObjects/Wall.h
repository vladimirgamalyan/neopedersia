#pragma once

#include "WorldObject.h"

class Wall : public WorldObject
{
public:
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;
    virtual Vec2 getDim() const;

private:

};
