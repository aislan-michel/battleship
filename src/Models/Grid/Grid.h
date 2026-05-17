#pragma once

#include <string>

#include "../Position/Position.h"

const int GridSize = 10;
const char SeaContent = '*';

enum class ShotResult
{
    Invalid,
    AlreadyShot,
    Miss,
    Hit
};

enum class PlaceShipResult
{
    Placed,
    InvalidDirection,
    OutOfBounds,
    Overlap
};

class Grid
{
private:
    Position positions[GridSize][GridSize];
    bool has_ship(int row, int col);
    bool is_inside_grid(int row, int col);
    void set_content_of_position(int row, int col, char content);
public:
    Grid();
    Position get_content(int x, int y);
    void print_grid();
    void print_ships();
    ShotResult shot(int x, int y);
    PlaceShipResult add_ship(int row_start_position, int col_start_position,
        std::string type_position, std::string ship_design);
};
