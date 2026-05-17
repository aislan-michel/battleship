#pragma once

void menu();
bool take_turn(class Player& attacker, class Player& defender, int& attacker_hits, int total_ship_parts);
void run_single_player();
void run_multi_player();
int run_game();
