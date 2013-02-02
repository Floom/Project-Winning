#pragma once
#include "Entity.h"

class Tile : public Entity
{



public:

	Tile(void);
	Tile(float fX, float fY);

	void Draw();
	void SetSprite();

	~Tile(void);

};

