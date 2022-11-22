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
	ofDrawRectangle(x, y, width, height);
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
}
