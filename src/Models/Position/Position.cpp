#include "Position.h"

Position::Position(char x)
{
    revealed = false;
    content = x;
}
char Position::get_content()
{
    return content;
}
void Position::set_content(char x)
{
    content = x;
}
bool Position::is_revealed()
{
    return revealed;
}

void Position::reveal()
{
    revealed = true;
}
