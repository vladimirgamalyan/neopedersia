#include "Mortar.h"
#include "Mortarball.h"
#include "../World.h"

void Mortar::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/mortar/mortar.png");
}

void Mortar::shot(WorldObject *worldObject)
{
    world->addWorldObject(new Mortarball(pos, worldObject->getPos(), getDamage()), pos);
}
