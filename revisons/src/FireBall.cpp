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
void FireBall::Setup()
{
	/*fireball1.loadImage("fireball.png");*/
	for (int i = 0; i < 6; i++)
	{
		animation[i].load("Part-4_Sprite_Images/fireball/tile0" + to_string(i) + ".png");
	}
}

void FireBall::Draw()
{
	ofSetColor(color);
	/*ofDrawRectangle(x, y, width, height);*/
	if(speedX > 0)
	{
		fireball1.draw(x, y, width, height);
	}
	if (speedX < 0)
	{
		fireball1.draw(x + width, y, -width, height);
	}
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
	if (frameNumber < 5)
	{
		fireball1 = animation[0];
	}
	else if (frameNumber < 10)
	{
		fireball1 = animation[1];
	}
	else if (frameNumber < 15)
	{
		fireball1 = animation[2];
	}
	else if (frameNumber < 20)
	{
		fireball1 = animation[3];
	}
	else if (frameNumber < 25)
	{
		fireball1 = animation[4];
	}
	else if (frameNumber < 30)
	{
		fireball1 = animation[5];
		frameNumber = 0;
	}
	frameNumber++;
}

