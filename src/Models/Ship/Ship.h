#pragma once

#include <string>

using namespace std;

class Ship
{
    int number;
    string class_of_ship;
    string design;
public:
    Ship() = default;
    Ship(int x, string y, string z);
    string get_number();
    string get_class_of_ship();
    string get_design();
};
