#pragma once

#include "WorldPainter.h"
#include "Config.h"

class Ground
{
public:
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;

private:
    static const int BIG_CELL = 3;
    void fill();
    void renderCell(const WorldPainter& worldPainter, int col, int row, int cell) const;
    std::string getCellTexture(int cell) const;
    bool inited = false;
    int cells[Config::World::WIDTH_CELL][Config::World::HEIGHT_CELL];
};
