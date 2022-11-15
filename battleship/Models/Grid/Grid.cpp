#include "Grid.h"

#include <iostream>

using namespace std;

Grid::Grid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            positions[i][j] = Position('*');
        }
    }

    /*positions[0][0].set_content("<");
    positions[0][1].set_content("=");
    positions[0][2].set_content(">");*/
}
Position Grid::get_content(int x, int y) 
{
    return positions[x][y];
}
void Grid::print_grid()
{   
    for (int i = 0; i < 10; i++)
    {
        if(i != 0)
        {
            cout << "\n";
        }
        
        for (int j = 0; j < 10; j++)
        {
            auto position = positions[i][j];
            
            if(position.is_sea())
            {
                cout << "|~";
            }
            else
            {
                cout << "|" << position.get_content();
            }
        }
    }
}
void Grid::print_ships()
{
    for (int i = 0; i < 10; i++)
    {
        if(i != 0)
        {
            cout << "\n";
        }
        
        for (int j = 0; j < 10; j++)
        {
            auto position = positions[i][j];
            
            if(position.get_content() != '*')
            {
                cout << "|" << position.get_content();
            }
            else
            {
                cout << "|~";
            }
        }
    }
}
void Grid::shot(int x, int y)
{
    const char bomb = '*'; 
    
    positions[x][y].set_sea(false);

    const auto content = positions[x][y].get_content();

    if(content == bomb)
    {
        cout << "\nyou found a bomb\n" << endl;
        return;
    }

    cout << "\nyou found a piece of ship\n" << endl;
}
void Grid::add_ship(
    int row_start_position, int col_start_position,
    std::string type_position, std::string ship_design)
{    
    const int ship_size = ship_design.length();
    int off = 0;

    if (type_position == "horizontal")
    {
        const int col_end_position = col_start_position + ship_size; 
        for (int j = col_start_position; j < col_end_position; j++)
        {
            auto position = positions[row_start_position][j];

            const auto content = ship_design[off];

            position.set_content(content);

            positions[row_start_position][j] = position;

            off++;
        }

        return;
    }

    if(type_position == "vertical")
    {
        const int row_end_position = row_start_position + ship_size;
        for (int i = row_start_position; i < row_end_position; i++)
        {
            auto position = positions[i][col_start_position];
            
            const auto content = ship_design[off];

            position.set_content(content);

            positions[i][col_start_position] = position;

            off++;
        }

        return;
    }

    throw invalid_argument("invalid type position");
}


