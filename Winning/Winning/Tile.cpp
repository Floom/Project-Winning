#include "Tile.h"
#include "misc\Functions.h"
#include "misc\Camera.h"

Tile::Tile(void)
{
	fWidth = 200.0f / 1.2f;
	fHeight = 200.0f / 3.0f;
}

void Tile::Draw()
{
	Functions::DrawIsoView(Sprite, vPosition.X - camera->iXPos, 
		vPosition.Y + camera->iYPos, fWidth, fHeight, color); 

}

void Tile::SetSprite()
{
	Sprite = Functions::LoadTexture("Assets\\images\\tile.png");

}

Tile::~Tile(void)
{
}
