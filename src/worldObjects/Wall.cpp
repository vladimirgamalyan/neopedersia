#include "Wall.h"

void Wall::update()
{

}

void Wall::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/walls/wall.png");
}

Vec2 Wall::getDim() const
{
    return Vec2(1, 1);
}
