#include "Game.h"

void Game::setIsGameRunning(bool gameRunning)
{
	isGameRunning = gameRunning;
}

bool Game::getIsGameRunning() const
{
	return isGameRunning;
}


void Game::setReplay(bool isReplaying)
{
	replay = isReplaying;
}

bool Game::getReplay() const
{
	return replay;
}



int Game::getCurrentLevel() const
{
	return currentLevel;
}

void Game::increaseCurrentLevel()
{
	currentLevel++;
}
