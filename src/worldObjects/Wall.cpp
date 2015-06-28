#include "Wall.h"

void Wall::update()
{

}

void Wall::render(const WorldPainter &worldPainter) const
{
    worldPainter.draw(pos, "assets/walls/wall.png");
}
