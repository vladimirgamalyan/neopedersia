#include "Ground.h"

void Ground::update()
{

}

void Ground::render(const WorldPainter& worldPainter) const
{
    worldPainter.draw(Point(0, 0), std::string("assets/tileset/tileset/prop_3x3.png"));
}
