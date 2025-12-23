#include "Characters.h"
#include "Items.h"
#include "Game.h"

#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using std::cout;
using std::endl;


int NUMBER_OF_ROWS = 30;
int NUMBER_OF_COLUMNS = 25;

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
	generateObjects(); // Generates in-game entities
	resetGame();
	loadMap();
	displayBoard();
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

/// <summary>
/// Retrieves the number of enemies within the level to display at the top of the screen
/// </summary>
/// <returns></returns>

int Game::getNumberOfEnemies()
{
	return numberOfEnemies;
}

/// <summary>
/// Set the number of enemies within the level to display at the top of the screen
/// </summary>
/// <param name="amountToAdd"></param>

void Game::setNumberOfEnemies(int amountToAdd)
{
	numberOfEnemies += amountToAdd;
}

/// <summary>
/// Retrieves the number of treasure chests within the level to display at the top of the screen
/// </summary>
/// <returns></returns>
int Game::getNumberOfChests()
{
	return numberOfChests;
}

/// <summary>
/// Set the number of treasure chests within the level to display at the top of the screen
/// </summary>
/// <param name="amountToAdd"></param>

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

	} while (keycode != 13); // While the ENTER key has not been pressed
}

/// <summary>
/// Creates the in-game entities
/// </summary>
void Game::generateObjects()
{
	playerCharacter = new PlayerCharacter; // Creates the player character (PC)

	for (int i = 0; i < (sizeof(enemies) / sizeof(enemies[0])); i++)
	{
		enemies[i] = new Enemy(i, 0.0f); // Creates a new enemy
	}

	for (int i = 0; i < (sizeof(coins) / sizeof(coins[0])); i++)
	{
		coins[i] = new Item("Coin", 'c', 1, 0, 0); // Creates a new coin
	}

	for (int i = 0; i < (sizeof(treasureChests) / sizeof(treasureChests[0])); i++)
	{
		treasureChests[i] = new Item("Chest", 'T', 50, 0, 0); // Creates a new treasure chest
	}

	for (int i = 0; i < (sizeof(walls)) / sizeof(walls[0]); i++)
	{
		walls[i] = new Item("Wall", '*', 0, 0, 0); // Creates a new wall
	}
}

void Game::resetGame()
{
	playerCharacter->setHealth(100);

	setNumberOfChests(-numberOfChests);
	setNumberOfEnemies(-numberOfEnemies);

	for (Item* wall : walls)
	{
		wall->deactivateItem();
	}

	for (Item* coin : coins)
	{
		coin->deactivateItem();
	}

	for (Item* chest : treasureChests)
	{
		chest->deactivateItem();
	}

	for (Enemy* enemy : enemies)
	{
		enemy->setHealth(-enemy->getHealth());
	}
}


void Game::loadMap() const
{
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			int tile = map[currentLevel][row][column];

			switch (tile)
			{
			case 1:

				playerCharacter->setXCoordinate(column);
				playerCharacter->setYCoordinate(row);
				break;

			case 2:

				for (Item* wall : walls)
				{
					if (!wall->getIsInteractable())
					{
						wall->setXCoordinate(column);
						wall->setYCoordinate(row);
						wall->activateItem();
						break;
					}
				}
				break;

			case 3:

				for (Enemy* enemy : enemies)
				{
					if (enemy->getHealth() <= 0.0f)
					{
						enemy->setHealth(50.0f);
						enemy->setXCoordinate(column);
						enemy->setYCoordinate(row);
						setNumberOfEnemies(1);
						break;
					}
				}
				break;

			case 4:
				for (Item* coin : coins)
				{
					if (!coin->getIsInteractable())
					{
						coin->setXCoordinate(column);
						coin->setYCoordinate(row);
						coin->activateItem();
						break;
					}
				}
				break;

			case 5:

				for (Item* chest : treasureChests)
				{
					if (!chest->getIsInteractable())
					{
						chest->setXCoordinate(column);
						chest->setYCoordinate(row);
						chest->activateItem();
						setNumberOfChests(1);
					}
				}
			}
		}
	}
}

/// <summary>
/// Displays the current state of the gameboard
/// </summary>
void Game::displayBoard()
{
	system("cls"); // Clears the console

	cout << "\033[33m";

	cout << endl << " PC Health: " << playerCharacter->getHealth() << " | "; // Display's the PC's current health
	cout << "Enemies: " << getNumberOfEnemies() << " | "; // Displays the current number of enemies
	cout << "Chests Remaining: " << getNumberOfChests() << " | "; // Displays the current number of chests
	cout << "Coins Collected: " << playerCharacter->getNumberOfCoins() << endl << endl; // Displays the number of coins collected

	char symbol = ' ';

	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			symbol = ' ';
			cout << "\033[0m";

			for (Item* wall : walls)
			{
				if (wall->getIsInteractable() && wall->getXCoordinate() == column && wall->getYCoordinate() == row) // Is the entity a wall?
				{
					cout << "\033[97m";
					symbol = wall->getSymbol(); // Output wall symbol to the console.
				}
			}

			for (Enemy* enemy : enemies)
			{
				if (enemy->getHealth() > 0 && enemy->getXCoordinate() == column && enemy->getYCoordinate() == row) // Is the entity an enemy?
				{
					cout << "\033[91m";
					symbol = enemy->getSymbol(); // Output enemy symbol to the console.
				}
			}

			for (Item* treasure : treasureChests)
			{
				if (treasure->getIsInteractable() && treasure->getXCoordinate() == column && treasure->getYCoordinate() == row) // Is the entity a treasure chest?
				{
					cout << "\033[93m";
					symbol = treasure->getSymbol(); // Output treasure chest symbol to the console.
				}
			}

			for (Item* coin : coins)
			{
				if (coin->getIsInteractable() && coin->getXCoordinate() == column && coin->getYCoordinate() == row) // Is the entity a coin?
				{
					cout << "\033[93m";
					symbol = coin->getSymbol(); // Output coin symbol to the console.
				}
			}

			if (playerCharacter->getHealth() > 0 && playerCharacter->getXCoordinate() == column && playerCharacter->getYCoordinate() == row) // Is the entity the player character?
			{
				symbol = playerCharacter->getSymbol(); // Output player character symbol to the console.
			}

			cout << ' ' << symbol << ' ';
		}

		cout << endl;
	}
}




/// <summary>
/// Checks whether the player character is colliding with another in-game entity
/// </summary>
/// <param name="xCoordinate"></param>
/// <param name="yCoordinate"></param>
/// <returns></returns>
bool Game::getIsOverlapping(int xCoordinate, int yCoordinate) const
{
	for (Item* wall : walls)
	{
		if (wall->getXCoordinate() == xCoordinate && wall->getYCoordinate() == yCoordinate && wall->getIsInteractable()) // Is the tile a wall?
		{
			return true;
		}
	}

	for (Enemy* enemy : enemies)
	{
		if (enemy->getXCoordinate() == xCoordinate && enemy->getYCoordinate() == yCoordinate && enemy->getHealth() > 0) // Is the tile an enemy?
		{
			return true;
		}
	}

	for (Item* coin : coins)
	{
		if (coin->getXCoordinate() == xCoordinate && coin->getYCoordinate() == yCoordinate && coin->getIsInteractable()) // Is the tile a coin?
		{
			return true;
		}
	}

	for (Item* chest : treasureChests)
	{
		if (chest->getXCoordinate() == xCoordinate && chest->getYCoordinate() == yCoordinate && chest->getIsInteractable()) // Is the tile a treasure chest?
		{
			return true;
		}
	}

	if (playerCharacter->getXCoordinate() == xCoordinate && playerCharacter->getYCoordinate() == yCoordinate) // Is the tile the PC?
	{
		return true;
	}

	return false;
}


void Game::checkForCollisions(int previousXPosition, int previousYPosition)
{
	for (Enemy* enemy : enemies)
	{
		if (enemy->getXCoordinate() == playerCharacter->getXCoordinate() && enemy->getYCoordinate() == playerCharacter->getYCoordinate() && enemy->getHealth() > 0) // Is PC colliding with an enemy?
		{
			fightEnemy(enemy->getID()); // Start the combat sequence
		}
	}

	for (Item* coin : coins)
	{
		if (coin->getIsInteractable() && coin->getXCoordinate() == playerCharacter->getXCoordinate() && coin->getYCoordinate() == playerCharacter->getYCoordinate()) // Is PC colliding with a coin?
		{
			playerCharacter->setNumberOfCoins(1); // Increases the coins collected counter at the top of the screen
			coin->deactivateItem(); // Deactivate the coin
		}
	}

	for (Item* wall : walls)
	{
		if (wall->getIsInteractable() && wall->getXCoordinate() == playerCharacter->getXCoordinate() && wall->getYCoordinate() == playerCharacter->getYCoordinate())
		{
			playerCharacter->setXCoordinate(-playerCharacter->getXCoordinate() + previousXPosition);
			playerCharacter->setYCoordinate(-playerCharacter->getYCoordinate() + previousYPosition); 
		}
	}
}

/// <summary>
/// The PvE combat system
/// </summary>
/// <param name="enemyIndex"></param>
void Game::fightEnemy(int enemyIndex)
{
	const int delay = 3000;

	setNumberOfEnemies(-1); // Reduces the enemy counter at the top of the screen

	while (enemies[enemyIndex]->getHealth() > 0 && playerCharacter->getHealth() > 0)
	{
		int playerInput = -1;

		while (playerInput != 1 && playerInput != 2 && playerInput != 3)
		{
			system("cls"); // Clears the console
			cout << "PC Health: " << playerCharacter->getHealth() << endl;
			cout << "Enemy " << enemyIndex << " Health: " << enemies[enemyIndex]->getHealth() << endl;
			cout << "\n\n\n\ Attack (1) || DEFEND (2) || GIVE UP (3) ";
			std::cin >> playerInput; 
		}

		switch (playerInput)
		{
		case 1: // PC attacks the enemy
			cout << "PC and the opponent attacked one another!" << endl;
			enemies[enemyIndex]->setHealth(-playerCharacter->getDamage()); // Redeuces the enemy's health
			
			if (enemies[enemyIndex]->getHealth() <= 0 && playerCharacter->getHealth()) // Is the enemy defeated before dealing any damage
			{
				break;
			}

			playerCharacter->setHealth(-enemies[enemyIndex]->getDamage()); // Redeuces the PC's health
			break;

		case 2: // PC blocks the incoming attack
			cout << "PC blocked the opponent's attack!" << endl;
			playerCharacter->setHealth(-enemies[enemyIndex]->getDamage() * 0.5); // Redeuces the PC's health
			break;

		case 3: // Player gives up
			cout << "PC gave up..." << endl;
			displayPlayerLostScreen(); // Display the Player Lost Screen
			break;

		default:
			return;
		}

		Sleep(delay);
	}

	if (enemies[enemyIndex]->getHealth() <= 0 && playerCharacter->getHealth() > 0) // Is the enemy defeated and is the PC alive?
	{
		cout << "The PC was victorious!" << endl;
	}
	else
	{
		cout << "YOU LOST..." << endl;
		displayPlayerLostScreen(); // Display the Player Lost Screen
	}

	Sleep(delay); // Causes a three second delay
}

void Game::CollectTreasure()
{
}

/// <summary>
/// Displays the Player Lost Screen
/// </summary>
void Game::displayPlayerLostScreen()
{
	char playerInput = ' ';

	system("cls");

	cout << "You lost..." << endl << "Play again (y/n)";

	while (playerInput != 'y' && playerInput != 'n')
	{
		playerInput = tolower(_getch());
	}

	if (playerInput == 'y') 
	{
		replay = true;
	}
	else if(playerInput == 'n')
	{
		replay = false;
	}
}


/// <summary>
/// Main Gameplay Loop
/// </summary>
void Game::updateGame()
{

	while (replay)
	{
		while (isGameRunning)
		{
			displayBoard();

			isGameRunning = playerCharacter->getHealth() > 0 ? true : false; // Checks whether the pc is still alive. 

			if (!isGameRunning)
			{
				return;
			}

			int previousXPosition = playerCharacter->getXCoordinate();
			int previousYPosition = playerCharacter->getYCoordinate(); 

			playerCharacter->move(getPlayerInput()); // Allows the pc to move using the WASD keys
			checkForCollisions(previousXPosition, previousYPosition); 
		}

		return; 
	}
}







