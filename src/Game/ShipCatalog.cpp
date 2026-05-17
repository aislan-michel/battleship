#include "ShipCatalog.h"

#include <iostream>
#include <string>

using namespace std;

Ship ships[ShipCatalogSize] = {
    Ship(1, "Carrier", "<===>"),
    Ship(2, "Battleship", "<==>"),
    Ship(3, "Destroyer", "<=>"),
    Ship(4, "Submarine", "<=>"),
    Ship(5, "Patrol Boat", "<>"),
};

void print_ships_catalog()
{
    cout << "\nAvailable ships:" << endl;

    for (auto ship : ships)
    {
        cout << ship.get_number()
            << " - " << ship.get_class_of_ship()
            << ": " << ship.get_design() << endl;
    }
}

bool has_selected_ship(int selected_ship_numbers[], int selected_count, int ship_number)
{
    for (int i = 0; i < selected_count; i++)
    {
        if(selected_ship_numbers[i] == ship_number)
        {
            return true;
        }
    }

    return false;
}

Ship get_ship_by_number(int ship_number)
{
    for (auto ship : ships)
    {
        if(ship.get_number() == to_string(ship_number))
        {
            return ship;
        }
    }

    return Ship();
}
