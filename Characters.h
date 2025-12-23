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

	// Getter and Setter methods 
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

	PlayerCharacter(); // Constructor

private:

	unsigned int numberOfCoins = 0;
	unsigned int numberOfPoints = 0;
	float damage = 25; 

public:

	// Getter and Setter methods

	int getNumberOfCoins() const;
	void setNumberOfCoins(int amountToAdd);

	int getAmountOfPoints() const;
	void setNumberOfPoints(int amountToAdd);

	float getDamage() const;


	// Other methods

	void movePC(int keycode);
};



class Enemy : public Character
{

public:

	Enemy(int pID, float pDamage = 10); // Constructor

private:

	int id = 0;
	float damage = 10.0f;

public:

	// Getter methods 

	int getID() const; 
	float getDamage() const;


	// Other methods

	void moveEnemy(int pcXPosition, int pcYPosition); 
};