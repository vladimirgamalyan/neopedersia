#pragma once

#include "WorldObject.h"

class Cannon : public WorldObject
{
public:
    Cannon();
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;
    virtual Vec2 getDim() const;

protected:
    virtual int getRange() const
    {
        return 30;
    }
    virtual int getDamage() const
    {
        return 30;
    }
    virtual int getCooldown() const
    {
        return 30;
    }
    virtual void shot(WorldObject *worldObject);

private:
    enum class State
    {
        STILL,
        COOLDOWN
    };

    void updateStill();
    void updateCoolDown();

    WorldObject* target = nullptr;
    State state;
    int cooldown;
};
