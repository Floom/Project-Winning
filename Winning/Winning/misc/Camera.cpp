#include "Camera.h"
#include <opengl\glwindow.h>
#include <misc\Functions.h>


Camera::Camera(float x, float y)
{
	iXPos = x;
	iYPos = y;
	p = GLWindow::getInstance();
	fCamSpeed = 2.0;
	Left = Up = Right = Down = OffsetX = OffsetY = 0;
}

void Camera::SetPos(float x, float y)
{
	iXPos = x - p->ScreenX / 2;
	iYPos = y - p->ScreenY / 2;;
}

void Camera::ChangePosBy(float x, float y)
{
	iXPos += x;
	iYPos += y;
}

void Camera::SetBorder(float _Left, float _Up, float _Right, float _Down, float _OffsetX, float _OffsetY)
{
	Left = _Left - _OffsetX;
	Up = _Up - _OffsetY;
	Right = _Right - _OffsetX;
	Down = _Down - _OffsetY;
}

void Camera::Update()
{
	fMouseX = p->GetMouseX();
	fMouseY = p->GetMouseY();

	if (iXPos < Right)
	{
		if (fMouseX > (p->ScreenX - 24) && fMouseX < 1024 || p->KeyDown(VK_RIGHT) || p->KeyDown('D'))
		{
			ChangePosBy(fCamSpeed, 0);
		}
	}
	if (iXPos > Left)
	{
		if (fMouseX < 20 && fMouseX > 0 || p->KeyDown(VK_LEFT) || p->KeyDown('A'))
		{
			ChangePosBy(-fCamSpeed, 0);
		
		}
	}
	if (iYPos < Up)
	{
		if (fMouseY > (p->ScreenY - 24) && fMouseY < 768 || p->KeyDown(VK_UP) || p->KeyDown('W'))
		{
			ChangePosBy(0, fCamSpeed);
		}
	}

	if (iYPos > Down)
	{
		if (fMouseY < 20 && fMouseY > 0 || p->KeyDown(VK_DOWN) || p->KeyDown('S'))
		{

			ChangePosBy(0, -fCamSpeed);
		
		}
	}



}



Camera::~Camera()
{
}
