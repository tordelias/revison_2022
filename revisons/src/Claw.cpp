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
	
}

void Claw::Draw()
{
	ofSetColor(color);
	//ofDrawRectangle(x, y, width, height);
	claw1.draw(x, y, width, height);
}
void Claw::Setup()
{
	claw1.loadImage("claw.png");
}


