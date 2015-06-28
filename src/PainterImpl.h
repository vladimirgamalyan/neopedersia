#pragma once

#include <map>
#include <SDL2pp/Texture.hh>
#include "Painter.h"

class PainterImpl : public Painter
{
public:
    PainterImpl(SDL2pp::Renderer& renderer) : renderer(renderer) {}
    virtual void draw(const Point& pos, const Texture& picture) const;
    virtual Size getTextureSize(const Texture& picture) const;

private:
    SDL2pp::Renderer& renderer;
    mutable std::map<std::string, SDL2pp::Texture> textures;
};
