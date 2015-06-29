#include "Ground.h"

void Ground::update()
{
    if (!inited)
    {
        fill();
        inited = true;
    }
}

void Ground::render(const WorldPainter& worldPainter) const
{
    for (int row = 0; row < ROW_COUNT; ++row)
        for (int col = 0; col < COL_COUNT; ++col)
            renderCell(worldPainter, col, row, cells[row][col]);
}

void Ground::fill()
{
    for (int row = 0; row < ROW_COUNT; ++row)
        for (int col = 0; col < COL_COUNT; ++col)
            cells[row][col] = 0;

    for (int row = 1; row < ROW_COUNT - 1; ++row)
        for (int col = 1; col < COL_COUNT - 1; ++col)
            cells[row][col] = 1;
}

void Ground::renderCell(const WorldPainter& worldPainter, int col, int row, int cell) const
{
    worldPainter.draw(Vec2(col * 28, row * 28), getCellTexture(cell));
}

std::string Ground::getCellTexture(int cell) const
{
    switch (cell)
    {
        case 1:
            return "assets/tiles/concrete.png";
    }
    return "assets/tiles/grass.png";
}
