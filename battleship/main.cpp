#include <iostream>
#include <string>

#include "Models/Grid/Grid.h"
#include "Models/Ship/Ship.h"

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

int main(int argc, char* argv[])
{
    cout << "\n** BattleShip **\n\n" << endl;

    Grid grid;

    grid.print_grid();

    int x;
    int y;
    
    cout << "\n\nenter a x: ";
    cin >> x;

    cout << "enter a y: ";
    cin >> y;

    auto position = grid.get_content(x, y);

    cout << "content: " + position.get_content() << endl;

    
    
    
    

    
    return 0;
}
