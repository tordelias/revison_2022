#pragma once
#include "ofApp.h"
class Hero
{


public:
	int x{0};
	int y{0};
	float width{0};
	float height{0};
	float speedY{0};
	float speedX{ 0 };
	ofColor color{ 0 };
	ofImage hero1;
	ofImage animation[10];
	int frameNumber{ 0 };
	Hero(int in_x, int in_y, float in_Width, float in_Height, ofColor in_Color);
	void Draw();
	void Update();
	void Setup();
};


