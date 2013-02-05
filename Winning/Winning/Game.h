#pragma once
#include "misc\Functions.h"
#include "fmod\Sound.h"
#include "Timer.h"

class Font;
class Map;
class Camera;

class Game
{
private:
	Font *fontA;
	int MouseX;
	int MouseY;

	Sound *soundA;
	FMOD::Sound *kalimba;
	
	Map *map;

	Timer *timer;

	Camera *camera;

	Color color;


public:
	Game(void);
	~Game(void);

	void Update();
	void Draw();

};

