#pragma once
#include <string>

class Player
{
    std::string name;
public:
    Player() = default;
    void set_name(std::string x);
};
