#include "Machinegun.h"
#include "../World.h"
#include "MachinegunBullet.h"

void Machinegun::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/mortar/mortar.png");
}

void Machinegun::shot(WorldObject *worldObject)
{
    world->addWorldObject(new MachinegunBullet(pos, worldObject, getDamage()), pos);
}
