#pragma once

class Game
{
public:

	Game(); // Constructor
	~Game(); // Deconstructor 

private:

	static int numberOfEnemies;
	static int numberOfChests;

	bool isGameRunning = true;
	bool replay = true;
	unsigned int currentLevel = 1;

public:

	// Getter and Setter Methods 

	void setIsGameRunning(bool gameRunning);
	bool getIsGameRunning() const;

	void setReplay(bool isReplaying);
	bool getReplay() const;

	int getCurrentLevel() const;
	void increaseCurrentLevel();

	static int getNumberOfEnemies();
	static void setNumberOfEnemies(int amountToAdd);

	static int getNumberOfChests();
	static void setNumberOfChests(int amountToAdd);


	// Other Methods 

	int getPlayerInput();
	void displayIntroMenu() const;
	void generateObjects();
	void displayBoard();
	void resetGame() const;
	bool getIsOverlapping(int xCoordinate, int yCoordinate) const;
	void updateGame();


private:
	int map[3][25][30] =
	{

	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
    ,2,0,0,0,0,2,4,0,0,0,5,2,0,0,0,0,0,0,0,0,0,0,4,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,1,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,5,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,2,2,2,2,2,2,2
    ,2,0,0,0,0,2,2,2,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,0,0,0,0,3,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,2,0,3,0,2
    ,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,3,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,2
    ,2,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,5,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
    ,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2

	}
};

