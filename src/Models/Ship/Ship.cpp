#include "Ship.h"

using namespace std;

Ship::Ship(int x, string y, string z)
{
    number = x;
    class_of_ship = y;
    design = z;
}
string Ship::get_class_of_ship()
{
    return class_of_ship;
}
string Ship::get_design()
{
    return design;
}
string Ship::get_number()
{
    return std::to_string(number);
}



