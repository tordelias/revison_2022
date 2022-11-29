#include "FireBall.h"
#include "GameManager.h"
#include "Hero.h"

FireBall::FireBall(float in_Width, float in_Height)
{
	width = in_Width;
	height = in_Height;
	color = ofColor::pink;
	y = ofRandom(0, ofGetWindowHeight() - height / 2);
	x = ofGetWindowWidth() - width;
	speedX = 3;
}

void FireBall::Draw()
{
	ofSetColor(color);
	ofDrawRectangle(x, y, width, height);
}

void FireBall::Move()
{
	x = x - speedX * ofGetLastFrameTime() * 50;
	if (x < 0 )
	{
		speedX *= -1;
	}
	if (x > ofGetWindowWidth() - width)
	{
		speedX *= -1;
		y = ofRandom(0, ofGetWindowHeight() - height / 2);
	}
	if (GameManager::CheckTwoRectangleCollide(
		x, y, width, height, superHero->x, superHero->y, superHero->width, superHero->height) == true)
	{
		GameManager::gameMode = GameManager::END_GAME;
	}
	if (GameManager::gameMode == GameManager::END_GAME)
	{
		y = ofRandom(0, ofGetWindowHeight() - height / 2);
		x = ofGetWindowWidth() - width;
	}
}
