#include "Characters.h"
#include "Items.h"

#include <iostream>

extern int NUMBER_OF_COLUMNS;
extern int NUMBER_OF_ROWS;
extern Item* walls[200];

// =========================================================================== //

// Character Class Member Functions 

/// <summary>
/// Retrieves the amount of health the character currently has
/// </summary>
/// <returns></returns>
float Character::getHealth() const
{
	return health;
}

/// <summary>
/// Updates the character's health when they regain health or recieve damage.
/// </summary>
/// <param name="amountToAdd"></param>
void Character::setHealth(float amountToAdd)
{
	health += amountToAdd;

	if (health > 100.0f)
	{
		health = 100.0f;
	}
}

/// <summary>
/// Retrieves the x-coordinate of the character's position on the board.
/// </summary>
/// <returns></returns>
int Character::getXCoordinate() const
{
	return xPosition;
}

/// <summary>
/// Retrieves the y-coordinate of the character's position on the board.
/// </summary>
/// <returns></returns>
int Character::getYCoordinate() const
{
	return yPosition;
}

/// <summary>
/// Updates the character's current x-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Character::setXCoordinate(int amountToAdd)
{
	xPosition += amountToAdd;
}

/// <summary>
/// Updates the character's current y-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Character::setYCoordinate(int amountToAdd)
{
	yPosition += amountToAdd;
}

/// <summary>
/// Retrieves the symbol which represents the character
/// </summary>
/// <returns></returns>
char Character::getSymbol() const
{
	return symbol;
}


// =========================================================================== //

// PlayerCharacter Class Member Functions 


/// <summary>
/// Constructor
/// </summary>
PlayerCharacter::PlayerCharacter()
{
	health = 100.0f;
	symbol = 'P';
	xPosition = 0;
	yPosition = 0;
	numberOfCoins = 0;
	numberOfPoints = 0;
}

/// <summary>
/// Retrieves the number of coins that the PC has collected 
/// </summary>
/// <returns></returns>
int PlayerCharacter::getNumberOfCoins() const
{
	return numberOfCoins;
}

/// <summary>
/// Retrieves the amount of points obtained
/// </summary>
/// <returns></returns>
int PlayerCharacter::getAmountOfPoints() const
{
	return numberOfPoints;
}

/// <summary>
/// Retrieves the damage inflicted by the PC
/// </summary>
/// <returns></returns>
float PlayerCharacter::getDamage() const
{
	return damage;
}

/// <summary>
/// Updates the player's score
/// </summary>
/// <param name="amountToAdd"></param>
void PlayerCharacter::setNumberOfPoints(int amountToAdd)
{
	numberOfPoints += amountToAdd;
}

void PlayerCharacter::move(int keycode)
{
	int newXCoordinate = -1;
	int newYCoordinate = -1;

	switch (keycode)
	{
	case 87: // W
		newXCoordinate = xPosition + 0;
		newYCoordinate = yPosition - 1; // PC moves up
		break;
	case 83: // S
		newXCoordinate = xPosition + 0;
		newYCoordinate = yPosition + 1; // PC moves down
		break;
	case 65: // A
		newXCoordinate = xPosition - 1; // PC moves left
		newYCoordinate = yPosition + 0;
		break;
	case 68: // D
		newXCoordinate = xPosition + 1; // PC moves right
		newYCoordinate = yPosition + 0;
		break;
	}

	if (newXCoordinate <= 0 || newXCoordinate >= NUMBER_OF_COLUMNS - 1 || newYCoordinate <= 0 || newYCoordinate >= NUMBER_OF_ROWS - 1) 
	{
		return;
	}
	else
	{
		xPosition = newXCoordinate; // Updates the PC's x-coordinate 
		yPosition = newYCoordinate; // Updates the PC's y-coordinate

		if (health <= 98)
		{
			health += 2; // PC health recovers overtime 
		}
	}
}

/// <summary>	
/// Updates the number of coins the PC has collected
/// </summary>
/// <param name="amountToAdd"></param>
void PlayerCharacter::setNumberOfCoins(int amountToAdd)
{
	numberOfCoins += amountToAdd;
}



// =========================================================================== //

// Enemy Class Member Functions 


/// <summary>
/// Constructor
/// </summary>
/// <param name="PDamage"></param>
Enemy::Enemy(int pID, float pDamage)
{
	symbol = 'W';
	xPosition = 0;
	yPosition = 0;
	damage = pDamage;
	health = 50.0f;
	id = pID; 
}

/// <summary>
/// Retrieves the enemy's ID, allowing PvE combat
/// </summary>
/// <returns></returns>
int Enemy::getID() const
{
	return id;
}

/// <summary>
/// Retrieves the damage the enemy will inflict onto the PC
/// </summary>
/// <returns></returns>
float Enemy::getDamage() const
{
	return damage;
}



