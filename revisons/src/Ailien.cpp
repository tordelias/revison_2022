#include "Ailien.h"
#include "ofApp.h"
#include "GameManager.h"
#include "Claw.h"

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
	if (gotCaught == false)
	{
		y = y + speedY * ofGetLastFrameTime() * 50;
		if (y <= 0 or y >= ofGetWindowHeight() - height)
		{
			speedY = speedY;
			speedY *= -1;
		}
		if (GameManager::CheckTwoRectangleCollide(
			x, y, width, height, claw->x, claw->y, claw->width, claw->height) == true)
		{
			gotCaught = true;
			claw->speedX = -1 * abs(claw->speedX);
			speedY = 0;

		}
	}
	else
	{
		x = claw->x + claw->width;
		y = (claw->y + claw->height / 2) - height / 2;
		if (claw->clawReleaced == false)
		{
			x = ofGetWindowWidth() - width;
			gotCaught = false;
			speedY = 3;
		}
	}

}
