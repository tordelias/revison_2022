#include "Claw.h"
#include "Hero.h"

Claw::Claw(float in_Width, float in_Height, shared_ptr<Hero> inHero)
{
width = in_Width;
height = in_Height;
color = ofColor::yellow;
theHero = inHero;

x = theHero->x + theHero->width;
y = theHero->y + theHero->height / 2 - height/2;

}
void Claw::Move()
{
	x = theHero->x + theHero->width;
	y = theHero->y + theHero->height / 2 - height / 2;
	
}

void Claw::Draw()
{
	ofSetColor(color);
	ofDrawRectangle(x, y, width, height);
}


