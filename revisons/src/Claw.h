#pragma once
#include "ofApp.h"
class Hero;
class Claw
{

	


public:
	int x{ 0 };
	int y{ 0 };
	float width{ 0 };
	float height{ 0 };
	float speedY{ 0 };
	ofColor color{ 0 };

	shared_ptr<Hero> theHero;

	Claw(float in_Width, float in_Height, shared_ptr<Hero> inHero);
	void Draw();
	void Move();

};

