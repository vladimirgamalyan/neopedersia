#include "PainterImpl.h"
#include <SDL2pp/Point.hh>
#include <SDL2pp/Renderer.hh>

void PainterImpl::draw(const Vec2 &pos, const Texture &texture, bool centered) const
{
    std::string fileName = texture.getFileName();
    std::map<std::string, SDL2pp::Texture>::iterator it = textures.find(texture.getFileName());
    if (it == textures.end())
    {
        it = textures.emplace(fileName, SDL2pp::Texture(renderer, fileName)).first;
        it->second.SetBlendMode(SDL_BLENDMODE_BLEND);
    }

    SDL2pp::Point p(pos.x, pos.y);

    if (centered)
    {
        const SDL2pp::Point& size = it->second.GetSize();
        p.x -= (size.x / 2.0);
        p.y -= (size.y / 2.0);
    }

    renderer.Copy(it->second, SDL2pp::NullOpt, p);
}

Vec2 PainterImpl::getTextureSize(const Texture &texture) const
{
    std::map<std::string, SDL2pp::Texture>::iterator it = textures.find(texture.getFileName());
    if (it == textures.end())
        return Vec2();
    const SDL2pp::Point& size = it->second.GetSize();
    return Vec2(size.x, size.y);
}

void PainterImpl::fillRect(const Rect &rect, const Color &color) const
{
    renderer.SetDrawColor(color.r, color.g, color.b, color.a);
    renderer.FillRect(rect.left(), rect.top(), rect.right(), rect.bottom());
}
