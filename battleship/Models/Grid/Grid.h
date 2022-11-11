#pragma once

#include "../Position/Position.h"

class Grid
{
    Position positions[10][10];
public:
    Grid();
    Position get_content(int x, int y);
    void print_grid();
    void shot(int x, int y);
};
