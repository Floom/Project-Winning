#include "Game.h"
#include "font\Font.h"
#include "Map.h"
#include "misc\Camera.h"

Game::Game(void)
{

	camera = new Camera(0.0f, 0.0f);
	
	
	fontA = new Font();

	soundA = new Sound;

	kalimba = soundA->CreateSound("Assets\\Sound\\kalimba.mp3",true);

	fontA->BuildFont("Times New Roman", 16, 16);

	//soundA->PlaySFX(kalimba,soundA->musicVolume);
	//soundA->PauseSound(true);

	map = new Map();
	map->AttachCameraToTiles(camera);

	camera->SetBorder(0, 0, map->HighX, map->HighY, 500, 500);
}


Game::~Game(void)
{
}


void Game::Update()
{
	MouseX = Functions::GetMouseX();
	MouseY = Functions::GetMouseY();

	camera->Update();

	soundA->system->update();

	soundA->ChangeVolumeSFX(soundA->sfxVolume - 0.0001);

	map->Update();
}

void Game::Draw()
{


	Functions::SetColor(1, 1, 1, 1, color);

	map->Draw();


	fontA->glPrint(100,100, 1, 0, 1, 1, "MouseX: %i", MouseX);
	fontA->glPrint(100,80, 1, 0, 1, 1, "MouseY: %i", MouseY);

	fontA->glPrint(100,200, 1, 0, 1, 1, "iXPos: %i", (int)camera->iXPos);
	fontA->glPrint(100,220, 1, 0, 1, 1, "iYPos: %i", (int)camera->iYPos);
}