#include "Game.h"

/// <summary>
/// Sets whether the game is stil running
/// </summary>
/// <param name="gameRunning"></param>
void Game::setIsGameRunning(bool gameRunning)
{
	isGameRunning = gameRunning;
}

/// <summary>
/// Retrieves whether the game is running
/// </summary>
/// <returns></returns>
bool Game::getIsGameRunning() const
{
	return isGameRunning;
}

/// <summary>
/// Sets whether the game is to be replayed
/// </summary>
/// <param name="isReplaying"></param>
void Game::setReplay(bool isReplaying)
{
	replay = isReplaying;
}

/// <summary>
/// Retrieves whether the game is going to be replayed.
/// </summary>
/// <returns></returns>
bool Game::getReplay() const
{
	return replay;
}


/// <summary>
/// Retrieves the current level
/// </summary>
/// <returns></returns>

int Game::getCurrentLevel() const
{
	return currentLevel;
}

/// <summary>
/// Increases the current level
/// </summary>
void Game::increaseCurrentLevel()
{
	currentLevel++;
}
