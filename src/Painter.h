#pragma once

#include "Texture.h"
#include "Vec2.h"
#include "Rect.h"
#include "Color.h"

class Painter
{
public:
    virtual void draw(const Vec2& pos, const Texture& texture, bool centered = false) const = 0;
    virtual void fillRect(const Rect& rect, const Color& color) const = 0;
    virtual Vec2 getTextureSize(const Texture& texture) const = 0;
};
