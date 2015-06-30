#pragma once
#include "../WorldPainter.h"
#include "../Vec2.h"
#include "WorldObjectId.h"

class World;

class WorldObject
{
public:
    virtual ~WorldObject() {}
    //TODO: Try constructor with World* arg.
    void assignWorld(World* world);
    virtual void update() = 0;
    virtual void render(const WorldPainter& worldPainter) const = 0;
    virtual void setPos(const Vec2& pos);
    virtual Vec2 getDim() const;
    virtual WorldObjectId getId() const;
    virtual bool isTargetable() const;
    virtual void hit(int damage);
    virtual void renderHealth(const WorldPainter& worldPainter) const;
    virtual int getFullHp() const;
    Vec2 getPos() const;
    bool isDead() const;

protected:
    World* world;
    Vec2 pos;
    int hp = 100;
};
