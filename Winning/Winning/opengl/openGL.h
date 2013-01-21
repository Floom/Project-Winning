#ifndef _openGL_H
#define _openGL_H

class OpenGL
{
public:
    OpenGL();

	bool FlipY;
    bool Init();
    void shutdown();

    void Resize(int width, int height);

	void Update();

};

#endif
