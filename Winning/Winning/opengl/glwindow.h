#ifndef _GLWINDOW_H
#define _GLWINDOW_H

#include <windows.h>
#include <ctime>
#include <string>
#include <unordered_map>


class OpenGL;

class GLWindow 
{
private:

    OpenGL* m_openGL; //A link to the example program
    bool m_isRunning; //Is the window still running?
    bool m_isFullscreen; 
	bool curKeyState[256];
	bool prevKeyState[256];

	static GLWindow *window;
	
	GLWindow(); //default constructor
	GLWindow(const GLWindow&);
    GLWindow& operator=(const GLWindow&);   

    HWND m_hwnd; //Window handle
    HGLRC m_hglrc; //Rendering context
    HDC m_hdc; //Device context
    RECT m_windowRect; //Window bounds
    HINSTANCE m_hinstance; //Application instance
    WNDCLASSEX m_windowClass;

    void setupPixelFormat(void);
    OpenGL* getAttachedExample() { return m_openGL; }

    float m_lastTime;	

public:
	std::string windowName;
    bool create(int width, int height, int bpp, bool fullscreen);
	bool FlipY;
    void destroy();
    void processEvents();
    void attachExample(OpenGL* openGL);
	bool KeyPressed(char letter);
	bool KeyDown(char letter);
	bool KeyUp(char letter);
	float GetMouseX();
	float GetMouseY();
	POINT mousePos;

	std::tr1::unordered_map<std::string, int> SpriteTable;

	float ScreenX;
	float ScreenY;

    bool Update(); //Is the window running?

    void swapBuffers() { SwapBuffers(m_hdc); }

    static LRESULT CALLBACK StaticWndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static GLWindow* getInstance();

    float getElapsedSeconds();

};

#endif