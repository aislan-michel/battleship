#pragma once

#include <string>

enum class CoordinateInput
{
    Value,
    Quit,
    Invalid
};

void clear_input();
bool read_int(const std::string& label, int& value);
CoordinateInput read_coordinate(const std::string& label, int& coordinate);
