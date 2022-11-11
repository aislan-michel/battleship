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

    positions[0][0].set_content("<");
    positions[0][1].set_content("=");
    positions[0][2].set_content(">");
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
            auto position = positions[i][j];
            
            if(position.is_sea())
            {
                std::cout << "|~";
            }
            else
            {
                std::cout << "|" + position.get_content();
            }
        }
    }
}
void Grid::shot(int x, int y)
{
    positions[x][y].set_sea(false);
}

