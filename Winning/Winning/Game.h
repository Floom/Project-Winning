#pragma once
#include "misc\Functions.h"

class Font;

class Game
{
private:
	Font *fontA;
	int MouseX;
	int MouseY;

	int testpic;

	Color color;


public:
	Game(void);
	~Game(void);

	void Update();
	void Draw();

};

