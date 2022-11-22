#pragma once
#include "ofApp.h"
class Claw;
class Ailien
{

public:
	int x{ 0 };
	int y{ 0 };
	float width{ 0 };
	float height{ 0 };
	float speedY{ 0 };
	ofColor color{ 0 };

	bool gotCaught{ false };
	shared_ptr<Claw> claw;

	Ailien(int in_x, int in_y, float in_Width, float in_Height, ofColor in_Color);
	void Draw();
	void Move();
};


