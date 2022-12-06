

#include "GameManager.h"
#include "ofApp.h"

void GameManager::DisplayOnScreenMesseger()
{
	if (GameManager::gameMode == GameManager::Start_SCREEN)
	{
		ofSetColor(255,255, 255);
		ofDrawBitmapString("Welcome to hero encounter Alien", 250, 250);
		ofDrawBitmapString("Press f to start", 250, 300);
		ofDrawBitmapString("Press g to shoot grabber", 250, 350);
	}

	else if (GameManager::gameMode == GameManager::END_GAME)
	{
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Fire crashed on Hero", 250, 250);
		ofDrawBitmapString("Press f to restart", 250, 300);
	}
	else if (GameManager::gameMode == GameManager::VICTORY)
	{
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("Well Done! Game End!", 250, 250);

	}
}

bool GameManager::CheckTwoRectangleCollide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	float totalHalfWidth = w1 / 2 + w2 / 2;
	float totalhalfHeight = h1 / 2 + h2 / 2;

	float totalDistanceX = abs((x1 + w1 / 2) - (x2 + w2 / 2));
	float totalDistanceY = abs((y1 + h1 / 2) - (y2 + h2 / 2));

	if (totalDistanceX <= totalHalfWidth and
		totalDistanceY <= totalhalfHeight)
	{
		return true;
	}

	return false;
}
