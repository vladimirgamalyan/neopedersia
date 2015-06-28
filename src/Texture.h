#pragma once

#include <string>

class Texture
{
public:
    Texture(const std::string& fileName);
    std::string getFileName() const;

private:
    std::string fileName;
};
