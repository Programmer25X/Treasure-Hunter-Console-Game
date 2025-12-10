#include "Game.h"

#include <iostream>
#include <conio.h>

Game::Game()
{
	std::cout << std::endl << std::endl << "- - - - - Game Started - - - - -" << std::endl; 

	welcomeMenu(); 
}

/// <summary>
/// Sets whether the game is stil running
/// </summary>
/// <param name="gameRunning"></param>
void Game::setIsGameRunning(bool gameRunning)
{
	isGameRunning = gameRunning;
}

/// <summary>
/// Retrieves whether the game is running
/// </summary>
/// <returns></returns>
bool Game::getIsGameRunning() const
{
	return isGameRunning;
}

/// <summary>
/// Sets whether the game is to be replayed
/// </summary>
/// <param name="isReplaying"></param>
void Game::setReplay(bool isReplaying)
{
	replay = isReplaying;
}

/// <summary>
/// Retrieves whether the game is going to be replayed.
/// </summary>
/// <returns></returns>
bool Game::getReplay() const
{
	return replay;
}

/// <summary>
/// Retrieves the current level
/// </summary>
/// <returns></returns>

int Game::getCurrentLevel() const
{
	return currentLevel;
}

/// <summary>
/// Increases the current level
/// </summary>
void Game::increaseCurrentLevel()
{
	currentLevel++;
}





int Game::getPlayerInput()
{
	int keycode = 0;

	std::cout << std::endl << "WASD - To Move | Esc - To Exit";
	do
	{
		keycode = toupper(_getch());

	} while (keycode == 27 || keycode == 87 || keycode == 83 || keycode == 65 || keycode == 68);

	if (keycode == 27)
	{
		isGameRunning = false; 
	}

	return keycode;
}

void Game::welcomeMenu() const
{
	system("cls");
	std::cout << "\033[32m"; 
	std::cout << std::endl << "\tTreasure Hunter";
	std::cout << std::endl << "\t- - - - - - - -  " << std::endl; 
	std::cout << std::endl << "\tCollect All the Treasure" << std::endl; 
	std::cout << std::endl << "\tAvoid All the Enemies" << std::endl;
}


