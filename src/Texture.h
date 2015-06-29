#pragma once

#include <string>

class Texture
{
public:
    Texture() {}
    Texture(const std::string& fileName);
    Texture(const char* fileName);
    std::string getFileName() const;

private:
    std::string fileName;
};
