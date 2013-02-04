#pragma once

class Tile;
class Camera;

class Map
{

public:
	Tile *tileArray[50][50];

	float HighX;
	float HighY;

	void Draw();
	void Update();
	void AttachCameraToTiles(Camera *camera);


	Map(void);
	~Map(void);
};

