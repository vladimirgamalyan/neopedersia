#pragma once

#include <map>
#include <SDL2pp/Texture.hh>
#include "Painter.h"

class PainterImpl : public Painter
{
public:
    PainterImpl(SDL2pp::Renderer& renderer) : renderer(renderer) {}
    virtual void draw(const Vec2& pos, const Texture& texture, bool centered = false) const;
    virtual Vec2 getTextureSize(const Texture& texture) const;

private:
    SDL2pp::Renderer& renderer;
    mutable std::map<std::string, SDL2pp::Texture> textures;
};
