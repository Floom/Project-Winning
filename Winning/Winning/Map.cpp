#include "Map.h"
#include "Tile.h"
#include "misc\Camera.h"


Map::Map(void)
{
	HighX = 0;
	HighY = 0;

	for (int x = 0; x < 50; ++x)
	{
		for (int y = 0; y < 50; ++y)
		{
			tileArray[x][y] = new Tile();
			tileArray[x][y]->SetSprite();
		}
	}

	for (int x = 0; x < 50; ++x)
	{
		for (int y = 0; y < 50; ++y)
		{
			
			int row = y % 2;

			float fOffset = 0;
			if (row  == 0)
			{
				fOffset = tileArray[x][y]->fWidth/2;
			}

			Vector2 tempVec((tileArray[x][y]->fWidth*x) + fOffset, 
				25 + (tileArray[x][y]->fHeight/2) *y);

			tileArray[x][y]->SetPosition(tempVec);

			HighX = tempVec.X;
			HighY = tempVec.Y;
		}
	}
}


Map::~Map(void)
{
}

void Map::Draw()
{

	for (int x = 0; x < 50; ++x)
	{
		for (int y = 0; y < 50; ++y)
		{
			tileArray[x][y]->Draw();	
		}
	}
	
}

void Map::Update()
{
	for (int x = 0; x < 50; ++x)
	{
		for (int y = 0; y < 50; ++y)
		{
			tileArray[x][y]->Update();	
		}
	}
}

void Map::AttachCameraToTiles(Camera *camera)
{
	for (int x = 0; x < 50; ++x)
	{
		for (int y = 0; y < 50; ++y)
		{
			tileArray[x][y]->AttachCamera(camera);
		}
	}
}