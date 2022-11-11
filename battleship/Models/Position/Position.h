#pragma once

#include <string>

class Position
{
    bool sea;
    std::string content;
public:
    Position() = default;
    Position(std::string x);
    std::string get_content();
    void set_content(std::string x);
    bool is_sea();
    void set_sea(bool x);
};
