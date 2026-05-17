#include "PlayerSetup.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "ShipCatalog.h"
#include "../Infrastructure/ConsoleInput.h"

using namespace std;

void select_ships(Player& player)
{
    int selected_ship_numbers[ShipsPerPlayer] = {};

    print_ships_catalog();
    cout << "\n" << player.get_name() << ", select three different ships" << endl;

    for (int i = 0; i < ShipsPerPlayer; i++)
    {
        int ship_number;

        if(!read_int("Ship number: ", ship_number))
        {
            i--;
            continue;
        }

        if(ship_number < 1 || ship_number > ShipCatalogSize)
        {
            cout << "\nInvalid ship number. Try again.\n" << endl;
            i--;
            continue;
        }

        if(has_selected_ship(selected_ship_numbers, i, ship_number))
        {
            cout << "\nYou already selected this ship. Choose another one.\n" << endl;
            i--;
            continue;
        }

        selected_ship_numbers[i] = ship_number;
        player.add_ship(i, get_ship_by_number(ship_number));
    }
}

Player create_player(int index)
{
    string player_name;

    cout << "\nPlayer " << index << ", enter your name: ";
    cin >> player_name;

    auto player = Player(player_name);
    select_ships(player);

    return player;
}

string describe_place_ship_result(PlaceShipResult result)
{
    if(result == PlaceShipResult::InvalidDirection)
    {
        return "Use horizontal or vertical.";
    }

    if(result == PlaceShipResult::OutOfBounds)
    {
        return "The ship does not fit on the board.";
    }

    if(result == PlaceShipResult::Overlap)
    {
        return "The ship overlaps another ship.";
    }

    return "Invalid ship position.";
}

void position_ships(Player& player)
{
    auto player_ships = player.get_ships();
    int row_start_position;
    int col_start_position;
    string type_position;

    cout << "\n" << player.get_name() << ", position your ships" << endl;
    cout << "Rows and columns go from 0 to 9." << endl;

    for (int j = 0; j < ShipsPerPlayer; j++)
    {
        auto class_of_ship = player_ships[j].get_class_of_ship();
        auto ship_design = player_ships[j].get_design();

        cout << "\nPosition the " << class_of_ship << " " << ship_design << endl;

        if(!read_int("row start position: ", row_start_position))
        {
            j--;
            continue;
        }

        if(!read_int("col start position: ", col_start_position))
        {
            j--;
            continue;
        }

        cout << "vertical or horizontal: ";
        cin >> type_position;

        const auto place_result = player.position_ship(row_start_position, col_start_position, type_position, ship_design);
        if(place_result != PlaceShipResult::Placed)
        {
            cout << "\n" << describe_place_ship_result(place_result) << " Try again.\n" << endl;
            j--;
            continue;
        }

        player.print_my_grid_with_ships();
        cout << "\n" << endl;
    }
}

void add_random_ships(Player& player)
{
    int selected_ship_numbers[ShipsPerPlayer] = {};

    for (int i = 0; i < ShipsPerPlayer; i++)
    {
        int ship_number = (rand() % ShipCatalogSize) + 1;

        if(has_selected_ship(selected_ship_numbers, i, ship_number))
        {
            i--;
            continue;
        }

        selected_ship_numbers[i] = ship_number;
        auto ship = get_ship_by_number(ship_number);
        player.add_ship(i, ship);

        while (true)
        {
            const auto row = rand() % GridSize;
            const auto col = rand() % GridSize;
            const auto direction = rand() % 2 == 0 ? "horizontal" : "vertical";

            if(player.position_ship(row, col, direction, ship.get_design()) == PlaceShipResult::Placed)
            {
                break;
            }
        }
    }
}

Player create_opponent()
{
    auto opponent = Player("Napoleon");
    add_random_ships(opponent);

    return opponent;
}

int get_total_ship_parts(Player& player)
{
    auto player_ships = player.get_ships();
    int total_ship_parts = 0;

    for (int i = 0; i < ShipsPerPlayer; i++)
    {
        total_ship_parts += static_cast<int>(player_ships[i].get_design().length());
    }

    return total_ship_parts;
}
