#include <iostream>
#include <string>

#include "Models/Grid/Grid.h"
#include "Models/Player/Player.h"
#include "Models/Ship/Ship.h"
#include "Models/Player/Player.h"

using namespace std;

void create_ships()
{
    Ship ships[5] = {
        Ship(1, "Carrier", 5),
        Ship(2, "Battleship", 4),
        Ship(3, "Destroyer", 3),
        Ship(4, "Submarine", 3),
        Ship(5, "Patrol Boat", 2),
    };
}

//todo: create a player 
    //player select 3 different ships
    //player position your ships
    //acceptable possitions: full horizontal or full vertical

//"design" of ships
    //carrier: <===>
    //battleship: <==>
    //destroyer: <=>
    //submarine: <=>
    //patrol boat: <>

void your_turn()
{
    
}

int main(int argc, char* argv[])
{
    string name;
    Player player;
    
    cout << "\n** BattleShip Game**\n" << endl;
    cout << "hi, enter your name: " ;
    cin >> name;

    player.set_name(name);
    
    Grid grid;
    int x, y;
    
    cout << "\nto quit input 10\n";
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
    }
    
    return 0;
}
