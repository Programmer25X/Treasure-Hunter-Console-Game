// Treasure Hunter Console Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main()
{
    Game* game = new Game;
    game->updateGame();
    delete game; 
    return 0;
}

