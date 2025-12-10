#pragma once

class Character
{
protected:

	int health = 0;
	int xPosition = 0;
	int yPosition = 0;
	char symbol = ' ';

public:

	int getHealth() const;
	void setHealth();

	int getXPosition() const;
	int getYPosition() const;
	void setXPosition();
	void setYPosition();

	char getSymbol() const;
};
