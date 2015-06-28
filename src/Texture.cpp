#include "Texture.h"

Texture::Texture(const std::string &fileName) : fileName(fileName)
{
}

std::string Texture::getFileName() const
{
    return fileName;
}
