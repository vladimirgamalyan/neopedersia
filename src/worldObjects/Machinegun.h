#pragma once

#include "Cannon.h"

class Machinegun : public Cannon
{
public:
    virtual void render(const WorldPainter& worldPainter) const;

protected:
    virtual void shot(WorldObject *worldObject);
    virtual int getCooldown() const
    {
        return 5;
    }
    virtual int getDamage() const
    {
        return 2;
    }
private:

};
