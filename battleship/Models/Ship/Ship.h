#pragma once

#include <string>

class Ship
{
    int number;
    std::string classOfShip;
    int size;
public:
    Ship() = default;
    Ship(int x, std::string y, int z); 
};
