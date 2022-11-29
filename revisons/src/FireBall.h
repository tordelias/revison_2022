#pragma once
#include "ofApp.h"
class Hero;
class FireBall
{
public:
	int x{ 0 };
	int y{ 0 };
	float width{ 0 };
	float height{ 0 };
	float speedX{ 0 };
	ofColor color{ 0 };
	int frameNumber{ 0 };
	shared_ptr<Hero> superHero;
	ofImage fireball1;
	ofImage animation[6];
	void Setup();
	FireBall(float in_Width, float in_Height);
	void Draw();
	void Move();
};

