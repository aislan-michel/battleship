#include "Grid.h"

#include <iostream>

Grid::Grid()
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
            std::cout << "\n";
        }
        
        for (int j = 0; j < 10; j++)
        {
            if(positions[i][j].is_sea())
            {
                std::cout << "| * |";
            }
        }
    }
}
