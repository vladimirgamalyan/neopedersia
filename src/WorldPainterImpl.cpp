#include "WorldPainterImpl.h"

void WorldPainterImpl::draw(const Vec2 &pos, const Texture &picture) const
{
    Vec2 size = painter.getTextureSize(picture);

    //TODO: Use Vec2f
    double x = (pos.x - pos.y) * 4.0;
    double y = ((pos.x + pos.y) / 2.0 ) * 4.0;

    x += offset.x;
    y += offset.y;

    x -= size.x / 2.0;
    y -= size.y / 2.0;

    Vec2 p(static_cast<int>(x), static_cast<int>(y));

    painter.draw(p, picture);
}

void WorldPainterImpl::setOffset(const Vec2 &offset)
{
    this->offset = offset;
}
