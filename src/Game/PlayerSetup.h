#pragma once

#include "../Models/Grid/Grid.h"
#include "../Models/Player/Player.h"

Player create_player(int index);
void select_ships(Player& player);
void position_ships(Player& player);
void add_random_ships(Player& player);
Player create_opponent();
int get_total_ship_parts(Player& player);
std::string describe_place_ship_result(PlaceShipResult result);
