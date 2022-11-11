#include "Position.h"

Position::Position(std::string x)
{
    content = x;
}
std::string Position::get_content()
{
    return content;
}
void Position::set_content(std::string x)
{
    content = x;
}
bool Position::is_sea()
{
    return sea;
}
