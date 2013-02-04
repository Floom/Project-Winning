#pragma once
#include "Entity.h"

struct Triangle;

class Tile : public Entity
{
private:
	Triangle *triOne;
	Triangle *triTwo;


public:



	Tile(void);
	Tile(float fX, float fY);

	void Draw();
	void Update();
	void SetSprite();

	~Tile(void);

};

