#include "Player.h"

#include <iostream>

Player::Player(std::string x)
{
    name = x;
}
std::string Player::get_name()
{
    return name;
}
Ship* Player::get_ships()
{
    return ships;
}

void Player::add_ship(int i, Ship x)
{
    ships[i] = x;
}
void Player::show_ships()
{
    std::cout << "\n" + name + ", this is your ships:" << std::endl;
    for (auto ship : ships)
    {
        std::cout << ship.get_class_of_ship() << endl;
    }
}
void Player::position_ship(
        int row_start_position, int col_start_position,
        std::string type_position, std::string ship_design)
{
    grid.add_ship(row_start_position, col_start_position, type_position, ship_design);
}
void Player::show_my_grid_with_ships()
{
    grid.print_ships();
}





