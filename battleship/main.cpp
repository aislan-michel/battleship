#include <iostream>
#include <string>

#include "Models/Grid/Grid.h"
#include "Models/Player/Player.h"
#include "Models/Ship/Ship.h"

using namespace std;

//todo: create a player 
    //player select 3 different ships
    //player position your ships
    //acceptable possitions: full horizontal or full vertical

Ship ships[5] = {
    Ship(1, "Carrier", "<===>"),
    Ship(2, "Battleship", "<==>"),
    Ship(3, "Destroyer", "<=>"),
    Ship(4, "Submarine", "<=>"),
    Ship(5, "Patrol Boat", "<>"),
};

void show_available_ships()
{
    string ships_list = "\navailable ships:";
    for (auto ship : ships)
    {
        ships_list.append("\n" + ship.get_number() + " - " + ship.get_class_of_ship() + ": " + ship.get_design());
    }
    
    cout << ships_list << endl;
}

int main(int argc, char* argv[])
{
    string player_name1;
    
    cout << "\n** BattleShip Game**\n" << endl;
    cout << "Player 1, enter your name: " ;
    cin >> player_name1;

    auto player1 = Player(player_name1);
    
    show_available_ships();

    string numbers_ship_player1[3];
    
    cout << "\n" + player1.get_name() + ", select three ships" << endl;

    for (auto i = 0; i < 3; i++)
    {
        cout << "type " << i + 1 << "ª number: ";
        cin >> numbers_ship_player1[i];
    }
    
    for (auto i = 0; i < 3; i++)
    {
        for (auto ship : ships)
        {
            auto number = numbers_ship_player1[i];
            
            if(ship.get_number() == number)
            {
                player1.add_ship(i, ship);
            }
        }
    }

    player1.show_ships();
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
