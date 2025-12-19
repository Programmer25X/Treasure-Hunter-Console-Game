#pragma once
#include <string>

class Character
{
protected:

	float health = 0;
	int xPosition = 0;
	int yPosition = 0;
	char symbol = ' ';

public:

	float getHealth() const;
	void setHealth(float amountToAdd);

	int getXCoordinate() const;
	int getYCoordinate() const;
	void setXCoordinate(int amountToAdd);
	void setYCoordinate(int amountToAdd);

	char getSymbol() const;
};



class PlayerCharacter : public Character
{

public:

	PlayerCharacter();

private:

	unsigned int numberOfCoins = 0;
	unsigned int numberOfPoints = 0;
	float damage = 25; 

public:

	int getNumberOfCoins() const;
	void setNumberOfCoins(int amountToAdd);

	int getAmountOfPoints() const;
	void setNumberOfPoints(int amountToAdd);

	float getDamage() const; 

	void move(int keycode);
};



class Enemy : public Character
{

public:

	Enemy(float PDamage = 10);

private:

	float damage = 10.0f;

public:

	float getDamage() const;
};