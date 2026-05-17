#include <cstdlib>
#include <ctime>

#include "Game/Game.h"

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    return run_game();
}
