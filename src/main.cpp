#include <iostream>
#include <limits>
#include <string>

#include "Models/Grid/Grid.h"
#include "Models/Player/Player.h"
#include "Models/Ship/Ship.h"

using namespace std;

Ship ships[5] = {
    Ship(1, "Carrier", "<===>"),
    Ship(2, "Battleship", "<==>"),
    Ship(3, "Destroyer", "<=>"),
    Ship(4, "Submarine", "<=>"),
    Ship(5, "Patrol Boat", "<>"),
};

Player players[2];

Player create_player(int index)
{
    string player_name;
    
    cout << "\nPlayer " << index << ", enter your name: " ;
    cin >> player_name;

    auto player = Player(player_name);
        
    string ships_list = "\navailable ships:";
    for (auto ship : ships)
    {
        ships_list.append("\n" + ship.get_number() + " - " + ship.get_class_of_ship() + ": " + ship.get_design());
    }
    
    cout << ships_list << endl;

    string numbers_ship_player[3];
    
    cout << "\n" + player.get_name() + ", select three ships" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "type " << i + 1 << "ª number: ";
        cin >> numbers_ship_player[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (auto ship : ships)
        {
            auto number = numbers_ship_player[i];
            
            if(ship.get_number() == number)
            {
                player.add_ship(i, ship);
            }
        }
    }

    return player;
}

void create_players(int players_count)
{
    if(players_count == 1)
    {
        players[0] = create_player(1);
    }
    
    for (auto i = 0; i < players_count; i++)
    {
        players[i] = create_player(i + 1);
    }
}

void menu()
{
    cout << "** BattleShip Game**" << endl;

    string options;

    options.append("1 - Single Player");
    options.append("\n2 - Multi Player");
    options.append("\n0 - Quit");

    cout << options << endl;

    cout << "> ";
}

void position_ships(Player& player)
{
    auto player_ships = player.get_ships();
    int row_start_position;
    int col_start_position;
    string type_position;

    cout << "\n" << player.get_name() + ", position your ships\n" << endl;
    for (int j = 0; j < 3; j++)
    {
        auto class_of_ship = player_ships[j].get_class_of_ship();
        auto ship_design = player_ships[j].get_design();
            
        cout << "position the " + class_of_ship << endl;
        cout << "row start position: ";
        cin >> row_start_position;
        cout << "col start position: ";
        cin >> col_start_position;
        cout << "\nvertical or horizontal: ";
        cin >> type_position;

        const auto place_result = player.position_ship(row_start_position, col_start_position, type_position, ship_design);
        if(place_result != PlaceShipResult::Placed)
        {
            cout << "\ninvalid ship position. Try again.\n" << endl;
            j--;
            continue;
        }

        player.print_my_grid_with_ships();

        cout << "\n" << endl;
    } 
}

Player create_oponent()
{
    auto oponent = Player("Napoleão Bonaparte");
    const string numbers_ship_player[3] = { "3", "5", "1"};

    for (int i = 0; i < 3; i++)
    {
        for (auto ship : ships)
        {
            auto number = numbers_ship_player[i];
            
            if(ship.get_number() == number)
            {
                oponent.add_ship(i, ship);
            }
        }
    }

    oponent.position_ship(0, 1, "horizontal", ships[2].get_design());
    oponent.position_ship(5, 7, "horizontal", ships[4].get_design());
    oponent.position_ship(9, 0 , "horizontal", ships[0].get_design());

    return oponent;
}

int get_total_ship_parts(Player& player)
{
    auto player_ships = player.get_ships();
    int total_ship_parts = 0;

    for (int i = 0; i < 3; i++)
    {
        total_ship_parts += static_cast<int>(player_ships[i].get_design().length());
    }

    return total_ship_parts;
}

bool read_coordinate(const string& label, int& coordinate)
{
    cout << label;

    if(cin >> coordinate)
    {
        return true;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\ninvalid value. Type a number from 0 to 9.\n" << endl;

    return false;
}

int main(int argc, char* argv[])
{
    int option; //todo: create enum

    menu();
    cin >> option;
    
    if(option == 1) // single 
    {
        auto oponent = create_oponent();
        const auto total_ship_parts = get_total_ship_parts(oponent);
        int hits = 0;
        
        int x, y;
    
        while (hits < total_ship_parts)
        {
            auto& grid = oponent.get_grid();
            
            grid.print_grid();
            cout << "\n\nhits: " << hits << "/" << total_ship_parts;
        
            if(!read_coordinate("\n\nenter a x: ", x))
            {
                continue;
            }

            if(!read_coordinate("enter a y: ", y))
            {
                continue;
            }

            const auto shot_result = grid.shot(x, y);
            if(shot_result == ShotResult::Hit)
            {
                hits++;
            }
        }

        auto& grid = oponent.get_grid();
        grid.print_grid();
        cout << "\n\nYou win! You found all opponent ships.\n" << endl;

        return 0;
    }

    if(option == 2)
    {
        create_players(2);

        position_ships(players[0]);
        position_ships(players[1]);

        players[0].print_my_grid_with_ships();

        cout << string(4, '\n');
        
        players[1].print_my_grid_with_ships();
        int x, y;

        while (true)
        {
            auto& grid = players[0].get_grid();

            grid.print_grid();
        
            cout << "\n\nenter a x: ";
            cin >> x;

            cout << "enter a y: ";
            cin >> y;

            grid.shot(x, y);
        }

        return 0;

    }

    

    return 0;
}
