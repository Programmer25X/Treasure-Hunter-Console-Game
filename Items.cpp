#include "Items.h"

// CollectableItem Class Member Functions



Item::Item()
{

}

Item::Item(char pSymbol, int pXCoordinate, int pYcoordinate)
{
	symbol = pSymbol;
	xCoordinate = pXCoordinate;
	yCoordinate = pYcoordinate;
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

void Item::activateItem()
{
	isInteractable = true;
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
void Item::setXCoordinate(int amountToAdd)
{
	xCoordinate += amountToAdd;
}

/// <summary>
/// Updates the item's y-coordinate
/// </summary>
/// <param name="amountToAdd"></param>
void Item::setYCoordinate(int amountToAdd)
{
	yCoordinate += amountToAdd;
}



// ================================================================================= // 

// Treasure class member functions

Treasure::Treasure(char pSymbol, int pValue, int pXCoordinate, int pYcoordinate)
{
	symbol = pSymbol;
	value = pValue;
	xCoordinate = pXCoordinate;
	yCoordinate = pYcoordinate;

}

/// <summary>
/// Retrieves the value of the item
/// </summary>
/// <returns></returns>
int Treasure::getValue() const
{
	return value;
}



// =================================================================================== // 

// PressurePlate class member functions 

PressurePlate::PressurePlate(char pSymbol, int pId, int pXCoordinate, int pYcoordinate)
{
	symbol = pSymbol;
	id = pId;
	xCoordinate = pXCoordinate;
	yCoordinate = pYcoordinate;
}

int PressurePlate::getId() const
{
	return 0;
}
