#include <windows.h>
#include <opengl\glwindow.h>
#include <opengl\openGL.h>
#include <Game.h>

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR cmdLine,
                   int cmdShow)
{
    GLWindow *programWindow = GLWindow::getInstance();
	programWindow->windowName = "Game Test";

	//Set our window settings
    programWindow->ScreenX = 1024;
    programWindow->ScreenY = 768;
    const int windowBPP = 16; // Bits per pixel 16/32 
    const int windowFullscreen = false;

	programWindow->FlipY = true; // False is the default, False: (0,0) = bottom left, True: (0,0) = top left.

    OpenGL openGL;
	openGL.FlipY = programWindow->FlipY; // Set openGls direction.

    programWindow->attachExample(&openGL);

    if (!programWindow->create(programWindow->ScreenX, programWindow->ScreenY, windowBPP, windowFullscreen))
    {
        MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);

        programWindow->destroy(); 
        return 1;
    }

    if (!openGL.Init())
    {
        MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
        programWindow->destroy();
        return 1;
    }


	Game*newGame = new Game();


	// GAME LOOP:
	while(programWindow->Update())
    {
		openGL.Update();

		newGame->Update();
		newGame->Draw();

		programWindow->processEvents(); //Process any window events
		programWindow->swapBuffers();
    }

    openGL.shutdown();
    programWindow->destroy();

	return 0;
}