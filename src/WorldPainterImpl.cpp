#include "WorldPainterImpl.h"

void WorldPainterImpl::draw(const Point &pos, const Texture &picture) const
{
    painter.draw(pos, picture);
}
