#pragma once
class GameManager
{

public:
	enum STATUS {Start_SCREEN,RUN, END_GAME,VICTORY};

	static STATUS gameMode;
	static void DisplayOnScreenMesseger();

	static bool CheckTwoRectangleCollide(
		float x1, float y1, float w1, float h1, float x2, float y2,
		float w2, float h2
	);

};

