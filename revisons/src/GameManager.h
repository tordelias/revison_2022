#pragma once
class GameManager
{

public:
	enum STATUS {Start_SCREEN,RUN, END_GAME};

	static STATUS gameMode;
	static void DisplayOnScreenMesseger();

};

