#pragma once

#include "../Models/Ship/Ship.h"

const int ShipCatalogSize = 5;
const int ShipsPerPlayer = 3;

extern Ship ships[ShipCatalogSize];

void print_ships_catalog();
bool has_selected_ship(int selected_ship_numbers[], int selected_count, int ship_number);
Ship get_ship_by_number(int ship_number);
