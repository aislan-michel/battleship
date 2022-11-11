#include <iostream>
#include <string>

using namespace std;

class Ship
{
private:
    int number;
    string classOfShip;
    int size;
public:
    Ship() = default;
    Ship(int _number, string _classOfShip, int _size)
    {
        number = _number;
        classOfShip = _classOfShip;
        size = _size;
    }    
};

class Position
{
private:
    bool sea = true;
    string content;
public:
    Position() = default;
    Position(string x)
    {
        content = x;
    }
    string get_content()
    {
        return content;
    }
    void set_content(string x)
    {
        content = x;
    }
    bool is_sea()
    {
        return sea;
    }
};

class Grid
{
private:
    Position positions[10][10];

public:
    Grid()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                
                positions[i][j] = Position("");
            }
        }

        positions[0][0].set_content("part 1 of ship");
    }
    Position get_content(int x, int y) 
    {
        return positions[x][y];
    }
    void print_grid()
    {   
        for (int i = 0; i < 10; i++)
        {
            if(i != 0)
            {
                cout << "\n";
            }
        
            for (int j = 0; j < 10; j++)
            {
                if(positions[i][j].is_sea())
                {
                    cout << "| * |";
                }
            }
        }
    }
};

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
    string intro;
    intro.append("\n** BattleShip **\n\n");

    cout << intro << endl;

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
