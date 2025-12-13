#pragma once

class Game
{
public:

	Game(); // Constructor
	~Game(); // Deconstructor 

private:

	bool isGameRunning = false;
	bool replay = false;
	unsigned int currentLevel = 1;

public:

	// Getter and Setter Methods 

	void setIsGameRunning(bool gameRunning);
	bool getIsGameRunning() const;
	
	void setReplay(bool isReplaying);
	bool getReplay() const;

	int getCurrentLevel() const;
	void increaseCurrentLevel();


	// Other Methods 

	int getPlayerInput(); 
	void displayIntroMenu() const; 
	void generateObjects(); 
	void displayBoard();
	void resetGame();

};

