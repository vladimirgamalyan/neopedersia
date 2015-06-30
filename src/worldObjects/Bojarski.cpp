#include "Bojarski.h"

void Bojarski::update()
{

}

void Bojarski::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/bojarski/bojarski.png");
}

Vec2 Bojarski::getDim() const
{
    return Vec2(3, 3);
}
