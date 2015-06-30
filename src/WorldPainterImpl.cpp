#include "WorldPainterImpl.h"

void WorldPainterImpl::draw(const Vec2 &pos, const Texture &texture) const
{
    //TODO: Use Vec2f
    double x = (pos.x - pos.y) * 4.0;
    double y = ((pos.x + pos.y) / 2.0 ) * 4.0;

    x += offset.x;
    y += offset.y;

    Vec2 p(static_cast<int>(x), static_cast<int>(y));

    renderQueue.emplace(p, texture);
}

void WorldPainterImpl::drawUnordered(const Vec2 &pos, const Texture &texture) const
{
    //TODO: Use Vec2f
    double x = (pos.x - pos.y) * 4.0;
    double y = ((pos.x + pos.y) / 2.0 ) * 4.0;

    x += offset.x;
    y += offset.y;

    Vec2 p(static_cast<int>(x), static_cast<int>(y));

    painter.draw(p, texture, true);
}

void WorldPainterImpl::setOffset(const Vec2 &offset)
{
    this->offset = offset;
}

void WorldPainterImpl::drawQueue() const
{
    while (!renderQueue.empty())
    {
        const RenderQueueItem& i = renderQueue.top();
        painter.draw(i.pos, i.texture, true);
        renderQueue.pop();
    }
}

Vec2 WorldPainterImpl::worldToScreen(const Vec2 &pos)
{
    double x = (pos.x - pos.y) * 4.0;
    double y = ((pos.x + pos.y) / 2.0 ) * 4.0;

    return Vec2(static_cast<int>(x), static_cast<int>(y));
}
