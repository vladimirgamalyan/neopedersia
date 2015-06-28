#pragma once
#include "../WorldPainter.h"
#include "../Size.h"

class World;

class WorldObject
{
public:
    virtual ~WorldObject() {}
    //TODO: Try constructor with World* arg.
    void assignWorld(World* world);
    virtual void update() = 0;
    virtual void render(const WorldPainter& worldPainter) const = 0;
    virtual void setPos(const Point& pos);
    virtual Size getDim() const;
    Point getPos() const;
    bool isDead() const;

protected:
    World* world;
    Point pos;
    int hp = 1;
};
