#include "Items.h"

// CollectableItem Class Member Functions

/// <summary>
/// Constructor
/// </summary>
/// <param name="pName"></param>
/// <param name="pSymbol"></param>
/// <param name="pValue"></param>
Item::Item(std::string pName, char pSymbol, int pValue, int pXCoordinate, int pYcoordinate)
{
	name = pName;
	symbol = pSymbol;
	value = pValue; 
	xCoordinate = pXCoordinate;
	yCoordinate = pYcoordinate; 
}

/// <summary>
/// Retrieves the name of the item
/// </summary>
/// <returns></returns>
std::string Item::getName() const
{
	return name;
}

/// <summary>
/// Retrieves the symbol used to represent the item on the board 
/// </summary>
/// <returns></returns>
char Item::getSymbol() const
{
	return symbol; 
}

/// <summary>
/// Retrieves the value of the item
/// </summary>
/// <returns></returns>
int Item::getValue() const
{
	return value;
}

/// <summary>
/// Retrieves the item can be interacted with
/// </summary>
/// <returns></returns>
bool Item::getIsInteractable() const
{
	return isInteractable;
}

/// <summary>
/// Retrieves the item's y-coordinate
/// </summary>
/// <returns></returns>
int Item::getYCoordinate() const
{
	return yCoordinate;
}

/// <summary>
/// Retrieves the item's y-coordinate
/// </summary>
/// <returns></returns>
int Item::getXCoordinate() const
{
	return xCoordinate;
}

/// <summary>
/// Deactivates item
/// </summary>
void Item::deactivateItem()
{
	isInteractable = false;
}

/// <summary>
/// Updates the item's x-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Item::updateXCoordinate(int amountToAdd)
{
	xCoordinate += amountToAdd;
}

/// <summary>
/// Updates the item's y-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Item::updateYCoordinate(int amountToAdd)
{
	yCoordinate += amountToAdd;
}
