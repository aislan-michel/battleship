#pragma once

#include <string>

#include "../Position/Position.h"

class Grid
{
    Position positions[10][10];
public:
    Grid();
    Position get_content(int x, int y);
    void print_grid();
    void print_ships();
    void shot(int x, int y);
    void add_ship(int row_start_position, int col_start_position,
        std::string type_position, std::string ship_design);
};
