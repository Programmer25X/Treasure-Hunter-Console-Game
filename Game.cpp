#include "Characters.h"
#include "Items.h"
#include "Game.h"

#include <iostream>
#include <conio.h>
#include <ctime>

using std::cout;
using std::endl;



constexpr auto NUMBER_OF_ROWS = 25;
constexpr auto NUMBER_OF_COLUMNS = 30;

int Game::numberOfEnemies = 0;
int Game::numberOfChests = 0;

PlayerCharacter* playerCharacter = nullptr;
Enemy* enemies[5] = {};
Item* coins[10] = {};
Item* treasureChests[10] = {};
Item* walls[200] = {};

/// <summary>
/// Constructor
/// </summary>
Game::Game()
{
	cout << endl << endl << "- - - - - Game Started - - - - -" << endl; 

	displayIntroMenu(); // Displays the Intro Menu
}

/// <summary>
/// Deconstructor
/// </summary>
Game::~Game()
{

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

int Game::getNumberOfEnemies()
{
	return numberOfEnemies;
}

void Game::setNumberOfEnemies(int amountToAdd)
{
	numberOfEnemies += amountToAdd;
}

int Game::getNumberOfChests()
{
	return numberOfChests;
}

void Game::setNumberOfChests(int amountToAdd)
{
	numberOfChests += amountToAdd;
}


/// <summary>
/// Gets the Player's input to move the PC or exit the game 
/// </summary>
/// <returns></returns>
int Game::getPlayerInput()
{
	int keycode = 0;

	cout << endl << "WASD - To Move | Esc - To Exit";

	do
	{
		keycode = toupper(_getch()); // Gets the player's input

	} while (keycode != 27 && keycode != 87 && keycode != 83 && keycode != 65 && keycode != 68); // While not A, W, S, D or Escape

	if (keycode == 27) // Determines whether the player chooses to exit the game
	{
		isGameRunning = false; 
	}

	return keycode;
}

/// <summary>
/// Displays the Intro Menu
/// </summary>
void Game::displayIntroMenu() const
{
	int keycode = 0;


	system("cls"); // Clears the console#

	cout << "\033[33m"; 

	cout << endl << "\tTreasure Hunter";
	cout << endl << "\t- - - - - - - -  " << endl; 
	cout << endl << "\tCollect All the Treasure" << endl; 
	cout << endl << "\tAvoid All the Enemies" << endl; 

	cout << endl << endl << "\tPress ENTER to play" << endl;
	
	do
	{
		keycode = toupper(_getch());

	} while (keycode != 13);
}


void Game::generateObjects()
{
	playerCharacter = new PlayerCharacter; 

	for (int i = 0; i < (sizeof(enemies) / sizeof(enemies[0])); i++)
	{
		enemies[i] = new Enemy(30.0f);
	}

	for (int i = 0; i < (sizeof(coins) / sizeof(coins[0])); i++)
	{
		coins[i] = new Item("Coin", 'c', 1, 0, 0);
	}

	for (int i = 0; i < (sizeof(treasureChests) / sizeof(treasureChests[0])); i++)
	{
		treasureChests[i] = new Item("Chest", 'T', 50, 0, 0);
	}

	for (int i = 0; i < (sizeof(walls)) / sizeof(walls[0]); i++)
	{
		walls[i] = new Item("Wall", '*', 0, 0, 0);
	}
}


void Game::displayBoard() 
{
	system("cls");

	cout << "\033[33m";

	cout << endl << "Enemies: " << getNumberOfEnemies() << endl;
	cout << endl << "Chests Remaining: " << getNumberOfChests() << endl << endl;

	char symbol = ' ';

	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			symbol = ' ';
			cout << "\033[0m";

			for (Item* tile : walls)
			{
				if (tile->getIsInteractable() && tile->getXCoordinate() == column && tile->getYCoordinate() == row)
				{
					cout << "\033[97m";
					symbol = tile->getSymbol();
				}
			}

			for (Enemy* enemy : enemies)
			{
				if (enemy->getHealth() > 0 && enemy->getXCoordinate() == column && enemy->getYCoordinate() == row)
				{
					cout << "\033[91m";
					symbol = enemy->getSymbol();
				}
			}

			for (Item* treasure : treasureChests)
			{
				if (treasure->getIsInteractable() && treasure->getXCoordinate() == column && treasure->getYCoordinate() == row)
				{
					cout << "\033[93m";
					symbol = treasure->getSymbol();
				}
			}

			for (Item* coin : coins)
			{
				if (coin->getIsInteractable() && coin->getXCoordinate() == column && coin->getYCoordinate() == row)
				{
					cout << "\033[93m";
					symbol = coin->getSymbol();
				}
			}

			if (playerCharacter->getHealth() > 0 && playerCharacter->getXCoordinate() == column && playerCharacter->getYCoordinate() == row)
			{
				symbol = playerCharacter->getSymbol();
			}

			cout << ' ' << symbol << ' ';
		}

		cout << endl;
	}
}

void Game::resetGame() const
{
	bool isPCSpawned = false;

	int i = 0;

	int startXCoordinate = -1;
	int startYCoordinate = -1;

	srand(static_cast<unsigned int>(time(0)));
	
	setNumberOfEnemies(-numberOfEnemies);
	setNumberOfChests(-numberOfChests); 

	for (Item* wall : walls)
	{
		if (i < 30)
		{
			wall->setXCoordinate(i);
		}
		
		if (i >= 30 && i < 60)
		{
			wall->setXCoordinate(i - 30);
			wall->setYCoordinate(24);
		}
		
		if (i > 60 && i < 94)
		{
			wall->setYCoordinate(i - 60);
		}

		if (i >= 94 && i < 118)
		{
			wall->setXCoordinate(29);
			wall->setYCoordinate(i - 94);
		}

		if (i >= 118 && i < 128)
		{
			wall->setXCoordinate(i - 110);
			wall->setYCoordinate(12);
		}

		i++;
	}


	for (Enemy* enemy : enemies)
	{
		generateEnemyCoordinates: 

		startXCoordinate = rand() % NUMBER_OF_COLUMNS;
		startYCoordinate = rand() % NUMBER_OF_ROWS;

		if (getIsOverlapping(startXCoordinate, startYCoordinate))
		{
			goto generateEnemyCoordinates;
		}

		enemy->setXCoordinate(startXCoordinate);
		enemy->setYCoordinate(startYCoordinate);
		setNumberOfEnemies(1); 
	}


	for (Item* treasure : treasureChests)
	{
		generateTreasureCoordinates:

		startXCoordinate = rand() % NUMBER_OF_COLUMNS;
		startYCoordinate = rand() % NUMBER_OF_ROWS;

		if (getIsOverlapping(startXCoordinate, startYCoordinate))
		{
			goto generateTreasureCoordinates;
		}

		treasure->setXCoordinate(startXCoordinate);
		treasure->setYCoordinate(startYCoordinate);
		setNumberOfChests(1); 
	}


	for (Item* coin : coins)
	{
		generateCoinCoordinates:

		startXCoordinate = rand() % NUMBER_OF_COLUMNS;
		startYCoordinate = rand() % NUMBER_OF_ROWS;

		if (getIsOverlapping(startXCoordinate, startYCoordinate))
		{
			goto generateCoinCoordinates;
		}

		coin->setXCoordinate(startXCoordinate);
		coin->setYCoordinate(startYCoordinate);
	}
	

	while (!isPCSpawned)
	{
		startXCoordinate = rand() % NUMBER_OF_COLUMNS;
		startYCoordinate = rand() % NUMBER_OF_ROWS;

		if (!getIsOverlapping(startXCoordinate, startYCoordinate))
		{
			isPCSpawned = true;

			playerCharacter->setXCoordinate(startXCoordinate);
			playerCharacter->setYCoordinate(startYCoordinate);
		}
	}

}


bool Game::getIsOverlapping(int xCoordinate, int yCoordinate) const
{
	for (Item* wall : walls)
	{
		if (wall->getXCoordinate() == xCoordinate && wall->getYCoordinate() == yCoordinate)
		{
			return true;
		}
	}

	for (Enemy* enemy : enemies)
	{
		if (enemy->getXCoordinate() == xCoordinate && enemy->getYCoordinate() == yCoordinate && enemy->getHealth() > 0)
		{
			return true;
		}
	}

	for (Item* coin : coins)
	{
		if (coin->getXCoordinate() == xCoordinate && coin->getYCoordinate() == yCoordinate && coin->getIsInteractable())
		{
			return true;
		}
	}

	for (Item* chest : treasureChests)
	{
		if (chest->getXCoordinate() == xCoordinate && chest->getYCoordinate() == yCoordinate && chest->getIsInteractable())
		{
			return true;
		}
	}

	if (playerCharacter->getXCoordinate() == xCoordinate && playerCharacter->getYCoordinate() == yCoordinate)
	{
		return true;
	}

	return false;
}






