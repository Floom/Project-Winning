#pragma once
#include "misc\Vector2.h"
#include "misc\Functions.h"

class Camera;

class Entity
{
protected:
	Vector2 vPosition;


	int Sprite;

public:
	Entity(void);
	~Entity(void);

	float fWidth;
	float fHeight;

	Camera *camera;

	Color color;

	virtual void Draw() {}
	virtual void Update() {}
	virtual void SetSprite() = 0;

	void AttachCamera(Camera *_camera);

	Vector2 GetPosition() { return vPosition; }
	void SetPosition(Vector2 vPos) { vPosition = vPos; }

};

