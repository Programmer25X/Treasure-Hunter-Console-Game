#pragma once

class Game
{
private:

	bool isGameRunning = false;
	bool replay = false;
	unsigned int currentLevel = 1;

public:

	void setIsGameRunning(bool gameRunning);
	bool getIsGameRunning() const;
	
	void setReplay(bool isReplaying);
	bool getReplay() const;

	int getCurrentLevel() const;
	void increaseCurrentLevel();


};

