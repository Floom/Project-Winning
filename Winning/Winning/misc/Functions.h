#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <windows.h>
#include <gl/gl.h>
#include "Vector2.h"
#include <opengl\glwindow.h>

#define GL_BGRA 0x80E1
#define GL_RGBA 0x1908


struct _RotRect {
	Vector2 C;
	Vector2 S;
	float ang;
};

struct Color
{
	float R;
	float B;
	float G;
	float A;
};

namespace Functions
{
	void DrawLine(float x, float y, float endX, float endY, char R, char G, char B, char A );

	void DrawGrid(float cellsize, float gridsize);

	void DrawGridat(float cellsize, float gridsizew, float gidsizeh, float x, float y);
	
	void DrawTriangle(unsigned int sprite, float X, float Y, float Z, 
		float Width, float Height, Color color, float Angle = 0);

	void DrawRect(unsigned int sprite, float X, float Y, 
		float Width, float Height, Color color, float Angle = 0);

	void DrawRectCent(unsigned int sprite, float X, float Y, 
		float Width, float Height, Color color, float Angle = 0);
	
	void DrawIsoView(unsigned int sprite, float X, float Y, 
		float Width, float Height, Color color, float Angle = 0);

	bool AABBCollision(Vector2 vPos, Vector2 Vec2, float Width, 
		float Width2, float Height, float Height2);

	bool MouseRectCollision(float MouseX, float MouseY,
		float RectX, float RectY, float RectWidth, float RectHeight);

	// Rotated Rectangles Collision Detection, Oren Becker, 2001
	bool CheckRotRectCollision(_RotRect * rr1, _RotRect * rr2);

	unsigned int LoadTexture(const char* filename, GLenum image_format = GL_BGRA, 
		GLint internal_format = GL_RGBA, 
		GLint level = 0, GLint border = 0);

	bool UnloadTexture(const unsigned int texID);

	void SetColor(float R, float G, float B, float A, Color &color);

	bool IsKeyDown(int letter);

	bool IsKeyUp(int letter);

	int GetMouseX();

	int GetMouseY();

}

#endif