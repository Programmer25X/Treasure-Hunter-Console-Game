#include "Items.h"

// CollectableItem Class Member Functions

/// <summary>
/// Retrieves the name of the item
/// </summary>
/// <returns></returns>
std::string CollectableItem::getName() const
{
	return name;
}

/// <summary>
/// Retrieves the symbol used to represent the item on the board 
/// </summary>
/// <returns></returns>
char CollectableItem::getSymbol() const
{
	return symbol; 
}

/// <summary>
/// Retrieves the value of the item
/// </summary>
/// <returns></returns>
int CollectableItem::getValue() const
{
	return value;
}
