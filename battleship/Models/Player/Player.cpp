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




