#pragma once
#include <string>

#include "../Ship/Ship.h"
#include "../Grid/Grid.h"

class Player
{
    std::string name;
    Ship ships[3];
    Grid grid = Grid();
public:
    Player() = default;
    Player(std::string x);
    std::string get_name();
    Ship* get_ships(); 
    void add_ship(int i, Ship x);
    void show_ships();
    void position_ship(
        int row_start_position, int col_start_position,
        std::string type_position, std::string ship_design);
    void print_my_grid_with_ships();
    Grid get_grid();
    void set_grid(Grid x);
};
