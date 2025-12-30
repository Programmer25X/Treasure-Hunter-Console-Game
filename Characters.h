#pragma once
#include <string>

class Character
{

public:
	Character();

protected:

	float damage = 0;
	float health = 0;
	int xPosition = 0;
	int yPosition = 0;
	char symbol = ' ';

public:
	// Getter and Setter methods 

	float getHealth() const;
	void setHealth(float amountToAdd);

	float getDamage() const;

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
public:
	// Getter and Setter methods

	int getNumberOfCoins() const;
	void setNumberOfCoins(int amountToAdd);

	// Other methods

	void movePC(int keycode);
};



class Enemy : public Character
{
public:
	Enemy(int pId); // Constructor

private:
	int id = 0;

public:
	// Getter methods 

	int getID() const; 

	// Other methods

	void moveEnemy(int pcXPosition, int pcYPosition); 
};