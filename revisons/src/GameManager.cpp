

#include "GameManager.h"
#include "ofApp.h"

void GameManager::DisplayOnScreenMesseger()
{
	if (GameManager::gameMode == GameManager::Start_SCREEN)
	{
		ofDrawBitmapString("Welcome to my game", 250, 250);
	}

	else if (GameManager::gameMode == GameManager::END_GAME)
	{
		ofDrawBitmapString("You Lose", 250, 250);
	}
}
