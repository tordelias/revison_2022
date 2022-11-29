#include "Claw.h"
#include "Hero.h"

Claw::Claw(float in_Width, float in_Height, shared_ptr<Hero> inHero)
{
width = in_Width;
height = in_Height;
color = ofColor::darkMagenta;
theHero = inHero;

x = theHero->x + theHero->width;
y = theHero->y + theHero->height / 2 - height/2;

}
void Claw::Move()
{
	if(clawReleaced=true)
	{
		x = x + speedX * ofGetLastFrameTime() * 50;
	}
	y = theHero->y + theHero->height / 2 - height / 2;

	if (x >= ofGetWindowWidth() - width)
	{
		speedX *= -1;
	}
	if (x <= theHero->x + theHero->width)
	{
		speedX = 0;
		clawReleaced = false;
	}
	
	if (frameNumber < 5)
	{
		claw1 = animation[0];
	}
	else if (frameNumber < 10)
	{
		claw1 = animation[1];
	}
	else if (frameNumber < 15)
	{
		claw1 = animation[2];
	}
	else if (frameNumber < 20)
	{
		claw1 = animation[3];
	}
	else if (frameNumber < 25)
	{
		claw1 = animation[4];
	}
	else if (frameNumber < 30)
	{
		claw1 = animation[5];
	}
	else if (frameNumber < 35)
	{
		claw1 = animation[6];
	}
	else if (frameNumber < 40)
	{
		claw1 = animation[7];
		frameNumber = 0;
	}
	frameNumber++;
}

void Claw::Draw()
{
	ofSetColor(color);
	//ofDrawRectangle(x, y, width, height);
	if(clawReleaced == true && speedX > 0)
	{
		claw1.draw(x, y, width, height);
	}
	else
	{
		animation[1].draw(x, y, width, height);
	}
	//claw1.draw(x, y, width, height);
}
void Claw::Setup()
{
	/*claw1.loadImage("claw.png");*/
	for (int i = 0; i < 8; i++)
	{
		animation[i].load("Part-4_Sprite_Images/Claw/claw" + to_string(i) + ".png");
	}
}


