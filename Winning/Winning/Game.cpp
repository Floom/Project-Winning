#include "Game.h"
#include "font\Font.h"


Game::Game(void)
{
	testpic = Functions::LoadTexture("Assets\\rustle.png");



	fontA = new Font();
	fontA->BuildFont("Times New Roman", 16, 16);
}


Game::~Game(void)
{
}


void Game::Update()
{
	MouseX = Functions::GetMouseX();
	MouseY = Functions::GetMouseY();
}

void Game::Draw()
{
	fontA->glPrint(100,100, 1, 1, 1, 1, "MouseX: %i", MouseX);
	fontA->glPrint(100,80, 1, 1, 1, 1, "MouseY: %i", MouseY);

	Functions::SetColor(1, 1, 1, 1, color);

	Functions::DrawIsoView(testpic, 500, 0, 500, 500, color); 
	Functions::DrawRect(0, 500, 0, 5, 5, color); // This is just to show where the picture starts from.

}