#include "Position.h"

Position::Position(char x)
{
    sea = true;
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
bool Position::is_sea()
{
    return sea;
}

void Position::set_sea(bool x)
{
    sea = x;
}
