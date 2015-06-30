#pragma once

struct  Config
{
    struct World
    {
        static const int CELL_SIZE = 8;

        static const int WIDTH_CELL = 30;
        static const int HEIGHT_CELL = 30;

        static const int WIDTH = CELL_SIZE * WIDTH_CELL;
        static const int HEIGHT = CELL_SIZE * HEIGHT_CELL;
    };

};
