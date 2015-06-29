#pragma once

#include "WorldObject.h"

class Bojarski : public WorldObject
{
public:
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;
    
private:

};
