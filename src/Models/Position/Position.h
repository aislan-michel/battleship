#pragma once

class Position
{
    bool revealed;
    char content;
public:
    Position() = default;
    Position(char x);
    char get_content() const;
    void set_content(char x);
    bool is_revealed() const;
    void reveal();
};
