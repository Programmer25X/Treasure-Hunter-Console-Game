#pragma once

#include <string>	

// ============================================================ //

// Item class

class Item
{
public:
	Item(); 
	Item(char pSymbol, int pXCoordinate, int pYcoordinate); 

protected:

	char symbol = ' ';
	int xCoordinate = 0;
	int yCoordinate = 0;
	bool isInteractable = false;

public:

	char getSymbol() const;
	bool getIsInteractable() const;
	int getYCoordinate() const;
	int getXCoordinate() const;

	void activateItem();
	void deactivateItem();
	void setXCoordinate(int amountToAdd);
	void setYCoordinate(int amountToAdd);
};


// ======================================================== //

// PressurePlate class

class PressurePlate : public Item
{
public:
	PressurePlate(char pSymbol, int pId, int pXCoordinate, int pYcoordinate);

private:
	int id;

public:
	int getId() const; 
};


// ============================================================= // 

// Treasure class 

class Treasure : public Item
{
public:
	Treasure(char pSymbol, int pValue, int pXCoordinate, int pYcoordinate);

private:
	int value = 0;

public:
	int getValue() const;
};
