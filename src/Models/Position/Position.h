#pragma once

class Position
{
    bool sea;
    char content;
public:
    Position() = default;
    Position(char x);
    char get_content();
    void set_content(char x);
    bool is_sea();
    void set_sea(bool x);
};
