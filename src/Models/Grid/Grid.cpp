#include "Grid.h"

#include <iostream>

using namespace std;

char get_visible_content(const Position& position)
{
    if(!position.is_revealed())
    {
        return '~';
    }

    if(position.get_content() == SeaContent)
    {
        return 'o';
    }

    return position.get_content();
}

Grid::Grid()
{
    for (int i = 0; i < GridSize; i++)
    {
        for (int j = 0; j < GridSize; j++)
        {
            positions[i][j] = Position(SeaContent);
        }
    }
}

Position Grid::get_content(int x, int y) const
{
    return positions[x][y];
}

void Grid::print_grid()
{
    cout << "  ";
    for (int col = 0; col < GridSize; col++)
    {
        cout << " " << col;
    }

    for (int i = 0; i < GridSize; i++)
    {
        cout << "\n" << i << " ";

        for (int j = 0; j < GridSize; j++)
        {
            auto position = positions[i][j];

            cout << "|" << get_visible_content(position);
        }
    }
}

void Grid::print_ships()
{
    cout << "  ";
    for (int col = 0; col < GridSize; col++)
    {
        cout << " " << col;
    }

    for (int i = 0; i < GridSize; i++)
    {
        cout << "\n" << i << " ";

        for (int j = 0; j < GridSize; j++)
        {
            auto position = positions[i][j];

            if(position.get_content() != SeaContent)
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

ShotResult Grid::shot(int x, int y)
{
    if(!is_inside_grid(x, y))
    {
        cout << "\ninvalid position. Use values from 0 to 9.\n" << endl;
        return ShotResult::Invalid;
    }

    if(positions[x][y].is_revealed())
    {
        cout << "\nyou already shot this position\n" << endl;
        return ShotResult::AlreadyShot;
    }

    positions[x][y].reveal();

    const auto content = positions[x][y].get_content();

    if(content == SeaContent)
    {
        cout << "\nyou found a bomb\n" << endl;
        return ShotResult::Miss;
    }

    cout << "\nyou found a piece of ship\n" << endl;
    return ShotResult::Hit;
}

PlaceShipResult Grid::add_ship(
    int row_start_position,
    int col_start_position,
    std::string type_position,
    std::string ship_design)
{
    const int ship_size = static_cast<int>(ship_design.length());

    if(type_position != "horizontal" && type_position != "vertical")
    {
        return PlaceShipResult::InvalidDirection;
    }

    for (int off = 0; off < ship_size; off++)
    {
        const auto row = type_position == "vertical"
            ? row_start_position + off
            : row_start_position;
        const auto col = type_position == "horizontal"
            ? col_start_position + off
            : col_start_position;

        if(!is_inside_grid(row, col))
        {
            return PlaceShipResult::OutOfBounds;
        }

        if(has_ship(row, col))
        {
            return PlaceShipResult::Overlap;
        }
    }

    for (int off = 0; off < ship_size; off++)
    {
        const auto row = type_position == "vertical"
            ? row_start_position + off
            : row_start_position;
        const auto col = type_position == "horizontal"
            ? col_start_position + off
            : col_start_position;

        set_content_of_position(row, col, ship_design[off]);
    }

    return PlaceShipResult::Placed;
}

void Grid::set_content_of_position(int row, int col, char content)
{
    auto position = positions[row][col];

    position.set_content(content);

    positions[row][col] = position;
}

bool Grid::has_ship(int row, int col) const
{
    return positions[row][col].get_content() != SeaContent;
}

bool Grid::is_inside_grid(int row, int col) const
{
    return row >= 0 && row < GridSize && col >= 0 && col < GridSize;
}
