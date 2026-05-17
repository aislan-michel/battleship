#include "Game.h"

#include <iostream>
#include <string>

#include "PlayerSetup.h"
#include "../Infrastructure/ConsoleInput.h"
#include "../Models/Grid/Grid.h"
#include "../Models/Player/Player.h"

using namespace std;

Player players[2];

void create_players(int players_count)
{
    for (auto i = 0; i < players_count; i++)
    {
        players[i] = create_player(i + 1);
    }
}

void menu()
{
    cout << "** BattleShip Game **" << endl;
    cout << "1 - Single Player" << endl;
    cout << "2 - Multi Player" << endl;
    cout << "0 - Quit" << endl;
    cout << "> ";
}

bool take_turn(Player& attacker, Player& defender, int& attacker_hits, int total_ship_parts)
{
    int row;
    int col;
    auto& defender_grid = defender.get_grid();

    cout << "\n" << attacker.get_name() << "'s turn" << endl;
    cout << "Target: " << defender.get_name() << endl;
    defender_grid.print_grid();
    cout << "\n\nhits: " << attacker_hits << "/" << total_ship_parts;
    cout << "\nType q in any coordinate to quit." << endl;

    const auto row_result = read_coordinate("row: ", row);
    if(row_result == CoordinateInput::Quit)
    {
        return false;
    }
    if(row_result == CoordinateInput::Invalid)
    {
        return true;
    }

    const auto col_result = read_coordinate("col: ", col);
    if(col_result == CoordinateInput::Quit)
    {
        return false;
    }
    if(col_result == CoordinateInput::Invalid)
    {
        return true;
    }

    const auto shot_result = defender_grid.shot(row, col);
    if(shot_result == ShotResult::Hit)
    {
        attacker_hits++;
    }

    return true;
}

void run_single_player()
{
    auto player = Player("Player");
    auto opponent = create_opponent();
    const auto total_ship_parts = get_total_ship_parts(opponent);
    int hits = 0;

    while (hits < total_ship_parts)
    {
        if(!take_turn(player, opponent, hits, total_ship_parts))
        {
            cout << "\nGame finished by player.\n" << endl;
            return;
        }
    }

    opponent.get_grid().print_grid();
    cout << "\n\nYou win! You found all opponent ships.\n" << endl;
}

void run_multi_player()
{
    create_players(2);

    position_ships(players[0]);
    cout << string(4, '\n');
    position_ships(players[1]);
    cout << string(4, '\n');

    const auto total_parts_player_1 = get_total_ship_parts(players[0]);
    const auto total_parts_player_2 = get_total_ship_parts(players[1]);
    int player_1_hits = 0;
    int player_2_hits = 0;
    int current_player = 0;

    while (player_1_hits < total_parts_player_2 && player_2_hits < total_parts_player_1)
    {
        auto& attacker = players[current_player];
        auto& defender = players[current_player == 0 ? 1 : 0];
        auto& attacker_hits = current_player == 0 ? player_1_hits : player_2_hits;
        const auto target_total = current_player == 0 ? total_parts_player_2 : total_parts_player_1;

        if(!take_turn(attacker, defender, attacker_hits, target_total))
        {
            cout << "\nGame finished by player.\n" << endl;
            return;
        }

        if(attacker_hits == target_total)
        {
            break;
        }

        current_player = current_player == 0 ? 1 : 0;
    }

    const auto winner = player_1_hits == total_parts_player_2 ? players[0].get_name() : players[1].get_name();
    cout << "\n" << winner << " wins!\n" << endl;
}

int run_game()
{
    int option;

    menu();
    if(!(cin >> option))
    {
        cout << "\nInvalid option.\n" << endl;
        return 1;
    }

    if(option == 1)
    {
        run_single_player();
        return 0;
    }

    if(option == 2)
    {
        run_multi_player();
        return 0;
    }

    return 0;
}
