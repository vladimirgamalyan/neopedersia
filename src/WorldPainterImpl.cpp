#include "WorldPainterImpl.h"

void WorldPainterImpl::draw(const Point &pos, const Texture &picture) const
{
    Size size = painter.getTextureSize(picture);

    double x = (pos.x - pos.y) * 4.0;
    double y = ((pos.x + pos.y) / 2.0 ) * 4.0;

    x += offset.x;
    y += offset.y;

    x -= size.w / 2.0;
    y -= size.h / 2.0;

    Point p(static_cast<int>(x), static_cast<int>(y));

    painter.draw(p, picture);
}

void WorldPainterImpl::setOffset(const Vec2 &offset)
{
    this->offset = offset;
}
