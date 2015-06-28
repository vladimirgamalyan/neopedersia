#include "TownHall.h"

void TownHall::update()
{

}

void TownHall::render(const WorldPainter &worldPainter) const
{
    if (isDead())
    {
        worldPainter.draw(pos, "assets/townHall/townHallDestroyed.png");
        return;
    }
    worldPainter.draw(pos, "assets/townHall/townHall.png");
}
