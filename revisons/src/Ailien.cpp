#include "Ailien.h"
#include "ofApp.h"

Ailien::Ailien(int in_x, int in_y, float in_Width, float in_Height, ofColor in_Color)
{
	x = in_x;
	y = in_y;
	width = in_Width;
	height = in_Height;
	color = in_Color;
	speedY = 5;
}
void Ailien::Draw()
{
	ofSetColor(color);
	ofDrawRectangle(x, y, width, height);
}

void Ailien::Move()
{
	y = y + speedY * ofGetLastFrameTime() * 50;
	if (y <= 0 or y >= ofGetWindowHeight() - height)
	{
		speedY = speedY;
		speedY *= -1;
	}

}
