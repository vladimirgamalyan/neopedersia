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
    for (int row = 0; row < Config::World::HEIGHT_CELL; ++row)
        for (int col = 0; col < Config::World::WIDTH_CELL; ++col)
            renderCell(worldPainter, col, row, cells[row][col]);
}

void Ground::fill()
{
    for (int row = 0; row < Config::World::HEIGHT_CELL; ++row)
        for (int col = 0; col < Config::World::WIDTH_CELL; ++col)
            cells[row][col] = 0;

    for (int row = 0; row < Config::World::HEIGHT_CELL; row += BIG_CELL)
        for (int col = 0; col < Config::World::WIDTH_CELL; col += BIG_CELL)
            cells[row][col] = 1;

    for (int row = BIG_CELL; row < Config::World::HEIGHT_CELL - BIG_CELL; row += BIG_CELL)
        for (int col = BIG_CELL; col < Config::World::WIDTH_CELL - BIG_CELL; col += BIG_CELL)
            cells[row][col] = 2;
}

void Ground::renderCell(const WorldPainter& worldPainter, int col, int row, int cell) const
{
    if (cell)
    {
        col = col * Config::World::CELL_SIZE;
        row = row * Config::World::CELL_SIZE;
        worldPainter.drawUnordered(Vec2(col, row), getCellTexture(cell));
    }
}

std::string Ground::getCellTexture(int cell) const
{
    switch (cell)
    {
        case 1:
            return "assets/tiles/grass.png";
        case 2:
            return "assets/tiles/concrete.png";
        default:
            ;
    }
    return std::string();
}
