#include "Entity.h"
#include "misc\Functions.h"
#include "misc\Camera.h"

Entity::Entity(void)
{
	vPosition.X = 0.0f;
	vPosition.Y = 0.0f;
	fWidth = 0.0f;
	fHeight = 0.0f;

	Functions::SetColor(1, 1, 1, 1, color);

	Sprite = Functions::LoadTexture("Assets\\images\\debugtex.png");
}


Entity::~Entity(void)
{
}

void Entity::AttachCamera(Camera *_camera)
{
	camera = _camera;
}


