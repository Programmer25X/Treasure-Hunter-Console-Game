#pragma once

#include <string>	

class Item
{
public:
	Item(std::string pName, char pSymbol, int pValue, int pXCoordinate, int pYcoordinate); 

protected:

	std::string name = "";
	char symbol = ' ';
	int value = 0;
	int xCoordinate = 0;
	int yCoordinate = 0;
	bool isInteractable = false;

public:

	std::string getName() const;
	char getSymbol() const;
	int getValue() const;
	bool getIsInteractable() const;
	int getYCoordinate() const;
	int getXCoordinate() const;

	void activateItem();
	void deactivateItem();
	void setXCoordinate(int amountToAdd);
	void setYCoordinate(int amountToAdd);
};

class PressurePlate : public Item
{

};
