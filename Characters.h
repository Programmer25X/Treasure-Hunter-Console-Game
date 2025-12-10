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

	int getXPosition() const;
	int getYPosition() const;
	void setXPosition(int amountToAdd);
	void setYPosition(int amountToAdd);

	char getSymbol() const;
};



class PlayerCharacter : private Character
{

public:

	PlayerCharacter();

private:
	
	unsigned int numberOfCoins = 0;
	unsigned int numberOfPoints = 0;

public:
	
	int getNumberOfCoins() const;
	void setNumberOfCoins(int amountToAdd);
	
	int getAmountOfPoints() const;
	void setNumberOfPoints(int amountToAdd); 
};



class Enemy : private Character
{
	
public:

	Enemy(float PDamage = 10); 

private:

	float damage = 10.0f;
	std::string name = "";

public:
	float getDamage() const; 

};