#include "Tile.h"
#include "misc\Functions.h"
#include "misc\Camera.h"

Tile::Tile(void)
{
	fWidth = 200.0f / 1.2f;
	fHeight = 200.0f / 3.0f;
	triOne = new Triangle;
	triTwo = new Triangle;


}

void Tile::Draw()
{
	Functions::DrawIsoView(Sprite, vPosition.X - camera->iXPos, 
		vPosition.Y + camera->iYPos, fWidth, fHeight, color); 

}

void Tile::Update()
{
	Vector2 vMouse;
	vMouse.X = Functions::GetMouseX();
	vMouse.Y = Functions::GetMouseY();


	// Left Side of Tile
	triOne->P1.X = vPosition.X;
	triOne->P1.Y = vPosition.Y + fHeight/2;

	triOne->P2.X = vPosition.X + fWidth/2;
	triOne->P2.Y = vPosition.Y;

	triOne->P3.X = vPosition.X + fWidth/2;
	triOne->P3.Y = vPosition.Y + fHeight;

	//Right Side of Tile
	triTwo->P1.X = vPosition.X + fWidth/2;
	triTwo->P1.Y = vPosition.Y;

	triTwo->P2.X = vPosition.X + fWidth;
	triTwo->P2.Y = vPosition.Y + fHeight/2;

	triTwo->P3.X = vPosition.X + fWidth/2;
	triTwo->P3.Y = vPosition.Y + fHeight;

	

	if (Functions::TriangleCollision(*triOne, vMouse, camera))
	{

		Functions::SetColor(1, 0, 1, 1, color);
	}
	else if (Functions::TriangleCollision(*triTwo, vMouse, camera))
	{

		Functions::SetColor(1, 0, 1, 1, color);
	}
	else
	{
		// Set color back
		//Functions::SetColor(1, 1, 1, 1, color);
	}



}

void Tile::SetSprite()
{
	Sprite = Functions::LoadTexture("Assets\\images\\tile.png");

}

Tile::~Tile(void)
{
}
