#pragma once

#include <vector>
#include <queue>
#include "WorldPainter.h"
#include "Painter.h"

class WorldPainterImpl : public WorldPainter
{
public:
    WorldPainterImpl(Painter& painter) : painter(painter) {}
    virtual void setOffset(const Vec2& offset);
    virtual void drawUnordered(const Vec2& pos, const Texture& texture) const;
    virtual void draw(const Vec2& pos, const Texture & texture) const;
    //virtual void fillRect(const Rect& rect, const Color& color ) const;
    void drawQueue() const;
    Vec2 worldToScreen(const Vec2& pos) const;
    //Rect worldToScreen(const Rect& rect) const;
    virtual void fillRectEx(const Vec2& worldPos, const Rect& rect, const Color& color) const;

private:
    Painter& painter;
    Vec2 offset;

    struct RenderQueueItem
    {
        RenderQueueItem(const Vec2& pos, const Texture& texture ) : pos(pos), texture(texture) {}
        Vec2 pos;
        Texture texture;
    };

    struct RenderQueueItemComparator
    {
        bool operator() (const RenderQueueItem& a, const RenderQueueItem& b) const
        {
            return a.pos.y > b.pos.y;
        }
    };

    mutable std::priority_queue<RenderQueueItem,
            std::vector<RenderQueueItem>,
            RenderQueueItemComparator> renderQueue;
};
