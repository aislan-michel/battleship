#include <iostream>
#include <string>

#include "Models/Grid/Grid.h"
#include "Models/Player/Player.h"
#include "Models/Ship/Ship.h"

using namespace std;

Player players[2];

Ship ships[5] = {
    Ship(1, "Carrier", "<===>"),
    Ship(2, "Battleship", "<==>"),
    Ship(3, "Destroyer", "<=>"),
    Ship(4, "Submarine", "<=>"),
    Ship(5, "Patrol Boat", "<>"),
};

void create_players(int count)
{
    string player_name;
    
    for (auto i = 0; i < count; i++)
    {
        cout << "\nPlayer " << i + 1 << ", enter your name: " ;
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

        for (auto i = 0; i < 3; i++)
        {
            cout << "type " << i + 1 << "ª number: ";
            cin >> numbers_ship_player[i];
        }
    
        for (auto i = 0; i < 3; i++)
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

        player.show_ships();

        players[i] = player;
    }
}

int main(int argc, char* argv[])
{
    cout << "** BattleShip Game**" << endl;
    Grid grid;

    create_players(1);

    //position ships
    auto player1 = players[0];
    int row_start_position;
    int col_start_position;
    string type_position;

    cout << "position your ships\n" << endl;
    const auto player_ships = player1.get_ships();
    for (int i = 0; i < 3; i++)
    {
        cout << "position the " + player_ships[i].get_class_of_ship() << endl;
        cout << "row start position: ";
        cin >> row_start_position;
        cout << "col start position: ";
        cin >> col_start_position;
        cout << "\nvertical or horizontal:";
        cin >> type_position;

        grid.add_ship(row_start_position, col_start_position, type_position, player_ships[i].get_design());

        cout << "\n" << endl;

        grid.print_ships();

        cout << "\n" << endl;
    }

    

    
    
    
    
/*
    Grid grid;
    
    int x, y;
    
    cout << "\nto quit input 10\n\n";
    while (true)
    {        
        grid.print_grid();
        
        cout << "\n\nenter a x: ";
        cin >> x;

        cout << "enter a y: ";
        cin >> y;

        if(x == 10 || y == 10)
        {
            cout << "see you later" << endl;
            break;
        }

        grid.shot(x, y);
    }*/
    
    return 0;
}
