#pragma once

#include "Texture.h"
#include "Rect.h"
#include "Vec2.h"
#include "Color.h"

class WorldPainter
{
public:
    virtual void setOffset(const Vec2& offset) = 0;
    virtual void drawUnordered(const Vec2& pos, const Texture& texture) const = 0;
    virtual void draw(const Vec2& pos, const Texture& texture) const = 0;

    //virtual void fillRect(const Rect& rect, const Color& color ) const = 0;

    // Rect in screen coordinates relative worldPos, before scaling.
    virtual void fillRectEx(const Vec2& worldPos, const Rect& rect, const Color& color) const = 0;
};
