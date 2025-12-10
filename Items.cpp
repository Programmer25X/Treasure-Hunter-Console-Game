#include "Items.h"

// CollectableItem Class Member Functions

/// <summary>
/// Constructor
/// </summary>
/// <param name="pName"></param>
/// <param name="pSymbol"></param>
/// <param name="pValue"></param>
CollectableItem::CollectableItem(std::string pName, char pSymbol, int pValue)
{
	name = pName;
	symbol = pSymbol;
	value = pValue; 
}

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
