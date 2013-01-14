#ifndef _CAMERA_H_
#define _CAMERA_H_


class GLWindow;

class Camera
{
private:
	GLWindow *p;
	float fMouseX;
	float fMouseY;
	float fCamSpeed;
	float Left, Up, Right, Down, OffsetX, OffsetY;

public:
	float iXPos;
	float iYPos;

	Camera(float x, float y);
	void SetBorder(float _Left, float _Up, float _Right, float _Down, float _OffsetX = 0, float _OffsetY = 0);
	void SetPos(float x, float y);
	void ChangePosBy(float x, float y);
	void Update();
	int GetCameraPosX();
	int GetCameraPosY();
	~Camera();
};

#endif