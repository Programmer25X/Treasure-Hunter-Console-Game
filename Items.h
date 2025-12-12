#pragma once

#include <string>	

class Item
{
public:
	Item(std::string pName, char pSymbol, int pValue); 

private:

	std::string name = "";
	char symbol = ' ';
	int value = 0;
	int xCoordinate = 0;
	int yCoordinate = 0;
	bool isInteractable = true;

public:

	std::string getName() const;
	char getSymbol() const;
	int getValue() const;
	bool getIsInteractable() const;
	int getYCoordinate() const;
	int getXCoordinate() const;

	void deactivateItem();
	void updateXCoordinate(int amountToAdd);
	void updateYCoordinate(int amountToAdd);
};
