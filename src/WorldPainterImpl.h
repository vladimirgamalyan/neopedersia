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
    virtual void drawUnordered(const Vec2& pos, const Texture& picture) const;
    virtual void draw(const Vec2& pos, const Texture & picture) const;
    void drawQueue() const;

private:
    Painter& painter;
    Vec2 offset;

    struct RenderQueueItem
    {
        RenderQueueItem(const Vec2& pos, const Texture& picture ) : pos(pos), picture(picture) {}
        Vec2 pos;
        Texture picture;
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
