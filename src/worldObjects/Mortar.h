#pragma once

#include "Cannon.h"

class Mortar : public Cannon
{
public:
    virtual void render(const WorldPainter& worldPainter) const;

protected:
    virtual void shot(WorldObject *worldObject);
    virtual int getCooldown() const
    {
        return 180;
    }
private:

};
