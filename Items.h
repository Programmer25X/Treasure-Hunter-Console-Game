#pragma once

#include <string>	

class CollectableItem
{
private:

	std::string name = "";
	char symbol = ' ';
	int value = 0;

public:

	std::string getName() const;
	char getSymbol() const;
	int getValue() const;
};
