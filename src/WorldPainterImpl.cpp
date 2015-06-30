#include "WorldPainterImpl.h"

void WorldPainterImpl::draw(const Vec2 &pos, const Texture &texture) const
{
    renderQueue.emplace(worldToScreen(pos) + offset, texture);
}

void WorldPainterImpl::drawUnordered(const Vec2 &pos, const Texture &texture) const
{
    painter.draw(worldToScreen(pos) + offset, texture, true);
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

Vec2 WorldPainterImpl::worldToScreen(const Vec2 &pos) const
{
    double x = (pos.x - pos.y) * 4.0;
    double y = ((pos.x + pos.y) / 2.0 ) * 4.0;

    return Vec2(static_cast<int>(x), static_cast<int>(y));
}

//Rect WorldPainterImpl::worldToScreen(const Rect &rect) const
//{
//    return Rect(worldToScreen(rect.topLeft()), worldToScreen(rect.bottomRight()));
//}

//void WorldPainterImpl::fillRect(const Rect &rect, const Color &color) const
//{
    //Vec2
    //painter.fillRect(worldToScreen(rect) + offset, color);
//}

void WorldPainterImpl::fillRectEx(const Vec2 &worldPos, const Rect &rect, const Color& color) const
{
    Vec2 p(worldToScreen(worldPos) + rect.topLeft() + offset);
    painter.fillRect(Rect(p.x, p.y, rect.w, rect.h), color);
}
