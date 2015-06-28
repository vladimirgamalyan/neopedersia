#pragma once

#include "WorldPainter.h"

class Ground
{
public:
    virtual void update();
    virtual void render(const WorldPainter& worldPainter) const;

private:
    void fill();
    void renderCell(const WorldPainter& worldPainter, int col, int row, int cell) const;
    std::string getCellTexture(int cell) const;
    bool inited = false;
    static const int ROW_COUNT = 16;
    static const int COL_COUNT = 16;
    int cells[ROW_COUNT][COL_COUNT];
};
