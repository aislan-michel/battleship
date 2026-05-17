#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "../src/Models/Grid/Grid.h"
#include "../src/Models/Player/Player.h"
#include "../src/Models/Position/Position.h"
#include "../src/Models/Ship/Ship.h"

using namespace std;

void assert_true(bool condition, const string& message)
{
    if(!condition)
    {
        throw runtime_error(message);
    }
}

void assert_equal(char expected, char actual, const string& message)
{
    if(expected != actual)
    {
        throw runtime_error(message);
    }
}

void assert_equal(ShotResult expected, ShotResult actual, const string& message)
{
    if(expected != actual)
    {
        throw runtime_error(message);
    }
}

void assert_equal(PlaceShipResult expected, PlaceShipResult actual, const string& message)
{
    if(expected != actual)
    {
        throw runtime_error(message);
    }
}

void test_position_starts_hidden()
{
    Position position(SeaContent);

    assert_true(!position.is_revealed(), "Position should start hidden");

    position.reveal();

    assert_true(position.is_revealed(), "Position should be revealed after reveal()");
}

void test_grid_places_ship_horizontally()
{
    Grid grid;

    const auto result = grid.add_ship(0, 1, "horizontal", "<=>");

    assert_equal(PlaceShipResult::Placed, result, "Horizontal ship should be placed");
    assert_equal('<', grid.get_content(0, 1).get_content(), "Ship start should be placed at col 1");
    assert_equal('=', grid.get_content(0, 2).get_content(), "Ship middle should be placed at col 2");
    assert_equal('>', grid.get_content(0, 3).get_content(), "Ship end should be placed at col 3");
}

void test_grid_places_ship_vertically()
{
    Grid grid;

    const auto result = grid.add_ship(1, 0, "vertical", "<>");

    assert_equal(PlaceShipResult::Placed, result, "Vertical ship should be placed");
    assert_equal('<', grid.get_content(1, 0).get_content(), "Ship start should be placed at row 1");
    assert_equal('>', grid.get_content(2, 0).get_content(), "Ship end should be placed at row 2");
}

void test_grid_rejects_invalid_ship_positions()
{
    Grid grid;

    assert_equal(
        PlaceShipResult::InvalidDirection,
        grid.add_ship(0, 0, "diagonal", "<>"),
        "Grid should reject invalid direction");
    assert_equal(
        PlaceShipResult::OutOfBounds,
        grid.add_ship(9, 9, "horizontal", "<>"),
        "Grid should reject ships outside the board");

    assert_equal(PlaceShipResult::Placed, grid.add_ship(0, 0, "horizontal", "<>"), "First ship should be placed");
    assert_equal(
        PlaceShipResult::Overlap,
        grid.add_ship(0, 1, "vertical", "<>"),
        "Grid should reject overlapping ships");
}

void test_grid_shot_results()
{
    Grid grid;
    ostringstream output;
    auto* previous_output = cout.rdbuf(output.rdbuf());

    grid.add_ship(0, 1, "horizontal", "<>");

    assert_equal(ShotResult::Invalid, grid.shot(-1, 0), "Shot outside board should be invalid");
    assert_equal(ShotResult::Miss, grid.shot(0, 0), "Shot on sea should miss");
    assert_equal(ShotResult::AlreadyShot, grid.shot(0, 0), "Repeated shot should be rejected");
    assert_equal(ShotResult::Hit, grid.shot(0, 1), "Shot on ship should hit");

    cout.rdbuf(previous_output);
}

void test_grid_marks_missed_shot_as_revealed_sea()
{
    Grid grid;
    ostringstream output;
    auto* previous_output = cout.rdbuf(output.rdbuf());

    grid.shot(0, 0);

    cout.rdbuf(previous_output);

    const auto position = grid.get_content(0, 0);

    assert_true(position.is_revealed(), "Missed shot should reveal the position");
    assert_equal(SeaContent, position.get_content(), "Missed shot should keep sea content");
}

void test_player_exposes_mutable_grid()
{
    Player player("Ada");
    auto& grid = player.get_grid();

    grid.add_ship(0, 0, "horizontal", "<>");

    assert_equal('<', player.get_grid().get_content(0, 0).get_content(), "Player grid should be modified by reference");
}

void test_ship_getters()
{
    Ship ship(2, "Battleship", "<==>");

    assert_true(ship.get_number() == "2", "Ship number should be returned as string");
    assert_true(ship.get_class_of_ship() == "Battleship", "Ship class should be returned");
    assert_true(ship.get_design() == "<==>", "Ship design should be returned");
}

int main()
{
    void (*tests[])() = {
        test_position_starts_hidden,
        test_grid_places_ship_horizontally,
        test_grid_places_ship_vertically,
        test_grid_rejects_invalid_ship_positions,
        test_grid_shot_results,
        test_grid_marks_missed_shot_as_revealed_sea,
        test_player_exposes_mutable_grid,
        test_ship_getters,
    };

    int passed = 0;
    const int test_count = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < test_count; i++)
    {
        tests[i]();
        passed++;
    }

    cout << passed << " tests passed" << endl;

    return 0;
}
