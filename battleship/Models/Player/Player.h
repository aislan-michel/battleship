#pragma once
#include <string>

#include "../Ship/Ship.h"

class Player
{
    std::string name;
    Ship ships[3];
public:
    Player() = default;
    Player(std::string x);
    std::string get_name();
    Ship* get_ships(); 
    void add_ship(int i, Ship x);
    void show_ships();
};
