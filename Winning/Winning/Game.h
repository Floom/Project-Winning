#pragma once
#include "misc\Functions.h"
#include "fmod\Sound.h"

class Font;

class Game
{
private:
	Font *fontA;
	int MouseX;
	int MouseY;

	Sound *soundA;
	FMOD::Sound *kalimba;

	int testpic;

	Color color;


public:
	Game(void);
	~Game(void);

	void Update();
	void Draw();

};

