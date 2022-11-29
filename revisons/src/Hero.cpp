#include "Hero.h"
#include "ofApp.h"

Hero::Hero(int in_x, int in_y, float in_Width, float in_Height, ofColor in_Color)
{
	x = in_x;
	y = in_y;
	width = in_Width;
	height = in_Height;
	color = in_Color;
}
void Hero::Draw()
{
	ofSetColor(color);
	//ofDrawRectangle(x, y, width, height);
	hero1.draw(x, y, width, height);
}

void Hero::Update()
{
	y = y + speedY * ofGetLastFrameTime() * 50;

	if (y <= 0)
	{
		y = 0;
	}
	else if (y >= ofGetWindowHeight() - height)
	{
		y = ofGetWindowHeight() - height;
	}
	if (frameNumber < 5)
	{
		hero1 = animation[0];
	}
	else if (frameNumber < 10)
	{
		hero1 = animation[1];
	}
	else if (frameNumber < 15)
	{
		hero1 = animation[2];
	}
	else if (frameNumber < 20)
	{
		hero1 = animation[3];
	}
	else if (frameNumber < 25)
	{
		hero1 = animation[4];
	}
	else if (frameNumber < 30)
	{
		hero1 = animation[5];
	}
	else if (frameNumber < 35)
	{
		hero1 = animation[6];
	}
	else if (frameNumber < 40)
	{
		hero1 = animation[7];
	}
	else if (frameNumber < 45)
	{
		hero1 = animation[8];

	}
	else if (frameNumber < 50)
	{
		hero1 = animation[9];
		frameNumber = 0;
	}
	frameNumber++;
}
void Hero::Setup()
{
	/*hero1.loadImage("hero.png");*/
	for (int i = 0; i < 10; i++)
	{
		animation[i].load("Part-4_Sprite_Images/flying_man/tile0" + to_string(i) + ".png");
	}
}