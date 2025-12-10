#include "Characters.h"

/// <summary>
/// Retrieves the amount of health the character currently has
/// </summary>
/// <returns></returns>
int Character::getHealth() const
{
	return health;
}

/// <summary>
/// Updates the character's health when they regain health or recieve damage.
/// </summary>
/// <param name="amountToAdd"></param>
void Character::setHealth(int amountToAdd)
{

}

/// <summary>
/// Retrieves the x-coordinate of the character's position on the board.
/// </summary>
/// <returns></returns>
int Character::getXPosition() const
{
	return xPosition;
}

/// <summary>
/// Retrieves the y-coordinate of the character's position on the board.
/// </summary>
/// <returns></returns>
int Character::getYPosition() const
{
	return yPosition;
}

/// <summary>
/// Updates the character's current x-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Character::setXPosition(int amountToAdd)
{

}

/// <summary>
/// Updates the character's current y-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Character::setYPosition(int amountToAdd)
{
}


/// <summary>
/// Retrieves the symbol which represents the character
/// </summary>
/// <returns></returns>
char Character::getSymbol() const
{
	return symbol;
}
