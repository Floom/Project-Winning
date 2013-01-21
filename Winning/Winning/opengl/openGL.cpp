#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "openGL.h"

OpenGL::OpenGL()
{
	FlipY = false;
}

bool OpenGL::Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glAlphaFunc(GL_GREATER, 0.5);
	glEnable(GL_ALPHA_TEST);

	typedef void (APIENTRY * WGLSWAPINTERVALEXT) (int);
	WGLSWAPINTERVALEXT wglSwapIntervalEXT = (WGLSWAPINTERVALEXT) 
	wglGetProcAddress("wglSwapIntervalEXT");
	if (wglSwapIntervalEXT) {
	   wglSwapIntervalEXT(0); // disable vertical synchronisation
	}

    //Return success
    return true;
}

void OpenGL::shutdown()
{

}

void OpenGL::Resize(int width, int height)
{
    //glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   //gluPerspective(45.0f, float(width) / float(height), 1.0f, 100.0f);

	if (FlipY == false)
		gluOrtho2D(0, width, 0, height);
	else
		gluOrtho2D(0, width, height, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGL::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);

}


