/*
 *		This Code Was Created By Jeff Molofee 2000
 *		Modified by Shawn T. to handle (%3.2f, num) parameters.
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing The Base Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */
#ifndef FONT_H
#define FONT_H

#include <windows.h>		// Header File For Windows
#include <math.h>			// Header File For Windows Math Library
#include <stdio.h>			// Header File For Standard Input/Output
#include <stdarg.h>			// Header File For Variable Argument Routines
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <string>
#include <font\Font.h>

using namespace std;

class Font
{

	GLuint	base;	// Base Display List For The Font Set

	bool keys[256];	// Array Used For The Keyboard Routine

public:

	Font();
	~Font();
	GLvoid BuildFont(const char string[], float w, float h);
	GLvoid KillFont(GLvoid);
	GLvoid glPrint(float x, float y, float R, float G, float B, float A, string str, ...);
	GLvoid glPrint(float x, float y, float R, float G, float B, float A, const char *fmt, ...);
	//GLvoid glInput(int x, int y, float R, float G, float B, float A, string &str, GLWindow *p);

};



#endif

