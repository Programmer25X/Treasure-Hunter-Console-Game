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
Treasure* coins[10] = {};
Treasure* treasureChests[10] = {};
PressurePlate* pressurePlates[10] = {};
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
	delete playerCharacter;
	
	for (Item* wall : walls)
	{
		delete wall;
	}

	for (Treasure* chest : treasureChests)
	{
		delete chest;
	}

	for (Treasure* coin : coins)
	{
		delete coin;
	}

	for (Enemy* enemy : enemies)
	{
		delete enemy;
	}

	for (Item* pressurePlate : pressurePlates)
	{
		delete pressurePlate; 
	}
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


	system("cls"); // Clears the console

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
		coins[i] = new Treasure('c', 1, 0, 0); // Creates a new coin
	}

	for (int i = 0; i < (sizeof(treasureChests) / sizeof(treasureChests[0])); i++)
	{
		treasureChests[i] = new Treasure('T', 50, 0, 0); // Creates a new treasure chest
	}

	for (int i = 0; i < (sizeof(pressurePlates) / sizeof(pressurePlates[0])); i++)
	{
		pressurePlates[i] = new PressurePlate('P', i, 0, 0); // Creates a new pressure plate 
	}

	for (int i = 0; i < (sizeof(walls)) / sizeof(walls[0]); i++)
	{
		walls[i] = new Item('*', 0, 0); // Creates a new wall
	}
}

/// <summary>
/// Resets the state of the game 
/// </summary>
void Game::resetGame()
{
	// Reset the player character 
	playerCharacter->setHealth(100); 
	playerCharacter->setNumberOfCoins(-playerCharacter->getNumberOfCoins());
	playerCharacter->setXCoordinate(-playerCharacter->getXCoordinate());
	playerCharacter->setYCoordinate(-playerCharacter->getYCoordinate());

	setNumberOfChests(-numberOfChests); // Resets the number of treasure chests
	setNumberOfEnemies(-numberOfEnemies); // Resets the number of enemies


	for (Item* wall : walls) // Deactivates and resets the walls
	{
			wall->deactivateItem();
			wall->setXCoordinate(-wall->getXCoordinate());
			wall->setYCoordinate(-wall->getYCoordinate());
	}

	for (Treasure* coin : coins) // Deactivates resets the coins
	{
			coin->deactivateItem();
			coin->setXCoordinate(-coin->getXCoordinate());
			coin->setYCoordinate(-coin->getYCoordinate());
	}

	for (Treasure* chest : treasureChests) // Deactivates and resets the treasure chests
	{
			chest->deactivateItem();
			chest->setXCoordinate(-chest->getXCoordinate());
			chest->setYCoordinate(-chest->getYCoordinate());
	}

	for (Enemy* enemy : enemies) // Deactivates and resets the enemies
	{
			enemy->setHealth(-enemy->getHealth());
			enemy->setXCoordinate(-enemy->getXCoordinate());
			enemy->setYCoordinate(-enemy->getYCoordinate()); 
	}

	for (PressurePlate* pressurePlate : pressurePlates) // Deactivates and resets the pressure plates
	{
		pressurePlate->deactivateItem();
		pressurePlate->setXCoordinate(-pressurePlate->getXCoordinate());
		pressurePlate->setYCoordinate(-pressurePlate->getYCoordinate());
	}
}

/// <summary>
/// Loads the map for the current level
/// </summary>
void Game::loadMap() const
{
	for (int row = 0; row < NUMBER_OF_ROWS; row++) // Loops through each row on the gameboard
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++) // Loops through each column on the gameboard
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
						wall->activateItem(); // Activates the wall
						wall->setXCoordinate(column);
						wall->setYCoordinate(row);
						break;
					}
				}
				break;

			case 3:

				for (Enemy* enemy : enemies)
				{
					if (enemy->getHealth() <= 0.0f)
					{
						enemy->setHealth(50.0f); // Activates the enemy
						enemy->setXCoordinate(column);
						enemy->setYCoordinate(row);
						setNumberOfEnemies(1); // Increases the number of enemies
						break;
					}
				}
				break;

			case 4:
				for (PressurePlate* pressurePlate : pressurePlates)
				{
					if (!pressurePlate->getIsInteractable())
					{
						pressurePlate->setXCoordinate(column);
						pressurePlate->setYCoordinate(row);
						pressurePlate->activateItem();
						break;
					}
				}
				break;

			case 5:

				for (Treasure* chest : treasureChests)
				{
					if (!chest->getIsInteractable())
					{
						chest->activateItem(); // Activates the treasure chest
						chest->setXCoordinate(column);
						chest->setYCoordinate(row);
						setNumberOfChests(1); // Increases the number of treasure chests
						break;
					}
				}
				break;

			default:
				break;
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

			for (PressurePlate* pressurePlate : pressurePlates)
			{
				if (pressurePlate->getIsInteractable() && pressurePlate->getXCoordinate() == column && pressurePlate->getYCoordinate() == row) // Is the entity a pressure plate?
				{
					cout << "\033[93m";
					symbol = pressurePlate->getSymbol(); // Output pressure plate symbol to the console.
				}
			}

			if (playerCharacter->getHealth() > 0 && playerCharacter->getXCoordinate() == column && playerCharacter->getYCoordinate() == row) // Is the entity the player character (PC)?
			{
				symbol = playerCharacter->getSymbol(); // Output player character symbol to the console.
			}

			cout << ' ' << symbol << ' ';
		}

		cout << endl;
	}
}


/// <summary>
/// Checks if the PC is overlapping with an in-game entity
/// </summary>
/// <param name="previousXPosition"></param>
/// <param name="previousYPosition"></param>
void Game::checkForPcCollision(int previousXPosition, int previousYPosition)
{
	for (Enemy* enemy : enemies)
	{
		if (enemy->getXCoordinate() == playerCharacter->getXCoordinate() && enemy->getYCoordinate() == playerCharacter->getYCoordinate() && enemy->getHealth() > 0) // Is PC colliding with an enemy?
		{
			fightEnemy(enemy->getID()); // Start the combat sequence
		}
	}

	for (Treasure* coin : coins)
	{
		if (coin->getIsInteractable() && coin->getXCoordinate() == playerCharacter->getXCoordinate() && coin->getYCoordinate() == playerCharacter->getYCoordinate()) // Is PC colliding with a coin?
		{
			playerCharacter->setNumberOfCoins(1); // Increases the coins collected counter at the top of the screen
			coin->deactivateItem(); // Deactivate the coin
		}
	}

	for (Treasure* chest : treasureChests)
	{
		if (chest->getIsInteractable() && chest->getXCoordinate() == playerCharacter->getXCoordinate() && chest->getYCoordinate() == playerCharacter->getYCoordinate()) // Is PC colliding with a chest?
		{
			setNumberOfChests(-1); // Decreases the number of treasure chests remaining
			chest->deactivateItem(); // Deactivate the chest
		}
	}

	for (PressurePlate* pressurePlate : pressurePlates)
	{
		if (pressurePlate->getIsInteractable() && pressurePlate->getXCoordinate() == playerCharacter->getXCoordinate() && pressurePlate->getYCoordinate() == playerCharacter->getYCoordinate()) // Is PC colliding with a pressure plate?
		{
			openDoor(pressurePlate->getXCoordinate(), pressurePlate->getYCoordinate()); // Opens the locked door
			pressurePlate->deactivateItem(); // Deactivates the pressure plate
		}
	}

	for (Item* wall : walls)
	{
		if (wall->getIsInteractable() && wall->getXCoordinate() == playerCharacter->getXCoordinate() && wall->getYCoordinate() == playerCharacter->getYCoordinate()) // Is PC hitting a wall?
		{
			playerCharacter->setXCoordinate(-playerCharacter->getXCoordinate() + previousXPosition); // Return PC to previous x-coordinate (x position)
			playerCharacter->setYCoordinate(-playerCharacter->getYCoordinate() + previousYPosition); // Return PC to previous y-coordinate (y position)
		}
	}
}

/// <summary>
/// Moves the enemies within the level
/// </summary>
void Game::moveEnemies()
{
	for (Enemy* enemy : enemies)
	{
		int previousXPosition = enemy->getXCoordinate(); 
		int previousYPosition = enemy->getYCoordinate();

		enemy->moveEnemy(playerCharacter->getXCoordinate(), playerCharacter->getYCoordinate()); // Moves the enemy


		for (Item* wall : walls)
		{
			if (wall->getIsInteractable() && wall->getXCoordinate() == enemy->getXCoordinate() && wall->getYCoordinate() == enemy->getYCoordinate()) // Is enemy hitting a wall?
			{
				enemy->setXCoordinate(-enemy->getXCoordinate() + previousXPosition); // Return enemy to previous x-coordinate (x position)
				enemy->setYCoordinate(-enemy->getYCoordinate() + previousYPosition); // Return enemy to previous y-coordinate (y position)
			}
		}

		if (enemy->getXCoordinate() == playerCharacter->getXCoordinate() && enemy->getYCoordinate() == playerCharacter->getYCoordinate()) // Is enemy hitting the PC?
		{
			fightEnemy(enemy->getID()); // Start the combat sequence
		}
	}
}

/// <summary>
/// Activates the pressure plate and opens the corresponding door
/// </summary>
/// <param name="xPosition"></param>
/// <param name="yPosition"></param>
void Game::openDoor(int xPosition, int yPosition)
{
	switch (currentLevel)
	{
	case 0:
		if (xPosition == 8 && yPosition == 25)
		{
			for (Item* wall : walls)
			{
				if (wall->getXCoordinate() == 8 && wall->getYCoordinate() == 6) // First pressure plate
				{
					wall->deactivateItem(); // Unlocks the entrance
				}
			}
		}
		else if (xPosition == 6 && yPosition == 1)
		{
			for (Item* wall : walls)
			{
				if (wall->getXCoordinate() == 19 && wall->getYCoordinate() == 3) // First pressure plate
				{
					wall->deactivateItem(); // Unlocks the entrance
				}
			}
		}
		else if (xPosition == 22 && yPosition == 1)
		{
			for (Item* wall : walls)
			{
				if (wall->getXCoordinate() == 11 && wall->getYCoordinate() == 16) // First pressure plate
				{
					wall->deactivateItem(); // Unlocks the entrance
				}
			}
		}
		break;
	case 1:
		break;
	case 2:
		break;
	}
}

/// <summary>
/// The PvE combat system
/// </summary>
/// <param name="enemyIndex"></param>
void Game::fightEnemy(int enemyIndex)
{
	const unsigned int delay = 3000;

	setNumberOfEnemies(-1); // Reduces the enemy counter at the top of the screen

	while (enemies[enemyIndex]->getHealth() > 0 && playerCharacter->getHealth() > 0)
	{
		system("cls"); // Clears the console
		cout << "PC Health: " << playerCharacter->getHealth() << endl;
		cout << "Enemy " << enemyIndex << " Health: " << enemies[enemyIndex]->getHealth() << endl;

		char playerInput = ' ';

		while (playerInput != '1' && playerInput != '2' && playerInput != '3')
		{
			cout << endl << endl << endl << "Attack (1) || DEFEND (2) || GIVE UP (3)" << endl;
			playerInput = _getch(); 
		}

		switch (playerInput)
		{
		case '1': // PC attacks the enemy
			cout << "PC and the opponent attacked one another!" << endl;
			enemies[enemyIndex]->setHealth(-playerCharacter->getDamage()); // Redeuces the enemy's health
			
			if (enemies[enemyIndex]->getHealth() <= 0 && playerCharacter->getHealth() > 0) // Is the enemy defeated before dealing any damage
			{
				break;
			}
			else if (enemies[enemyIndex]->getHealth() > 0 && playerCharacter->getHealth() > 0)
			{
				playerCharacter->setHealth(-enemies[enemyIndex]->getDamage()); // Redeuces the PC's health
			}

			break;

		case '2': // PC blocks the incoming attack
			cout << "PC blocked the opponent's attack!" << endl;
			playerCharacter->setHealth(-enemies[enemyIndex]->getDamage() * 0.5f); // Redeuces the PC's health
			break;

		case '3': // Player gives up
			cout << "PC gave up..." << endl;
			displayPlayerLostScreen(); // Display the Player Lost Screen
			break;

		default:
			break;
		}

		if (enemies[enemyIndex]->getHealth() <= 0 && playerCharacter->getHealth() > 0) // Is the enemy defeated and is the PC alive?
		{
			cout << "The PC was victorious!" << endl;
		}
		else if(playerCharacter->getHealth() <= 0)
		{
			cout << "YOU LOST..." << endl;
			displayPlayerLostScreen(); // Display the Player Lost Screen
		}

		Sleep(delay); // Causes a three second delay
	}
}


/// <summary>
/// Displays the player defeat/lost menu
/// </summary>
void Game::displayPlayerLostScreen()
{
	char playerInput = ' ';

	system("cls"); // Clears the console

	cout << "You Lost..." << endl << "Play again (y/n)" << endl;

	while (playerInput != 'y' && playerInput != 'n')
	{
		playerInput = tolower(_getch());
	}

	if (playerInput == 'y') 
	{
		replay = true;
		isGameRunning = true;

		resetGame();
		loadMap();
	}
	else if(playerInput == 'n')
	{
		replay = false;
		isGameRunning = false;
	}
}

/// <summary>
/// Displays the player victory/win menu
/// </summary>
void Game::displayPlayerWonScreen()
{
	char playerInput = ' ';

	system("cls"); // Clears the console

	cout << "You Won!" << endl << "Play again (y/n)" << endl;

	while (playerInput != 'y' && playerInput != 'n')
	{
		playerInput = tolower(_getch());
	}

	if (playerInput == 'y')
	{
		replay = true;
		isGameRunning = true;

		resetGame();
		loadMap();
	}
	else if (playerInput == 'n')
	{
		replay = false;
		isGameRunning = false; 
	}
}

/// <summary>
/// Checks if the player has won or lost
/// </summary>
void Game::checkWin()
{
	if (numberOfChests <= 0)
	{
		displayPlayerWonScreen();
	}
}

/// <summary>
/// Main gameplay loop
/// </summary>
void Game::updateGame()
{
	while (replay)
	{
		while (isGameRunning)
		{
			displayBoard();

			isGameRunning = playerCharacter->getHealth() > 0 ? true : false; // Checks whether the PC is still alive. 

			if (!isGameRunning)
			{
				return;
			}

			int previousXPosition = playerCharacter->getXCoordinate();
			int previousYPosition = playerCharacter->getYCoordinate(); 

			playerCharacter->movePC(getPlayerInput()); // Allows the pc to move using the WASD keys
			moveEnemies();
			checkForPcCollision(previousXPosition, previousYPosition); 
			checkWin();
		}

		return; 
	}
}