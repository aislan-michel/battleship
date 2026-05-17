#pragma once

class Position
{
    bool revealed;
    char content;
public:
    Position() = default;
    Position(char x);
    char get_content();
    void set_content(char x);
    bool is_revealed();
    void reveal();
};
