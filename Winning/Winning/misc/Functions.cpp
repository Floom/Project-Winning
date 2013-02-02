#include <misc\Functions.h>
#include <freeimage\FreeImage.h>
#include <time.h>
#include <algorithm>
#include <stdint.h>

#ifndef M_PI    // in case we miss it in <cmath>
#define M_PI 3.14159265358979
#endif



namespace Functions
{

	unsigned int LoadTexture(const char* filename, GLenum image_format, GLint internal_format, GLint level, GLint border)
	{
		GLWindow *p = GLWindow::getInstance();

		// Hash map check -- HashMap is stored in the glwindow class.
		if (p->SpriteTable.find(filename) != p->SpriteTable.end())
		{
			return p->SpriteTable[filename];
		}

		//image format
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		//pointer to the image, once loaded
		FIBITMAP *dib(0);
		//pointer to the image data
		BYTE* bits(0);
		//image width and height
		unsigned int width(0), height(0);
		//OpenGL's image ID to map to
		GLuint gl_texID;
	
		//check the file signature and deduce its format
		fif = FreeImage_GetFileType(filename, 0);
		//if still unknown, try to guess the file format from the file extension
		if(fif == FIF_UNKNOWN) 
			fif = FreeImage_GetFIFFromFilename(filename);
		//if still unkown, return failure
		if(fif == FIF_UNKNOWN)
			return 0;

		//check that the plugin has reading capabilities and load the file
		if(FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, filename);
		//if the image failed to load, return failure
		if(!dib)
			return 0;

		//retrieve the image data
		bits = FreeImage_GetBits(dib);
		//get the image width and height
		width = FreeImage_GetWidth(dib);
		height = FreeImage_GetHeight(dib);
		//if this somehow one of these failed (they shouldn't), return failure
		if((bits == 0) || (width == 0) || (height == 0))
			return 0;

		// Non Power of two texture fix...
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		//generate an OpenGL texture ID for this texture
		glGenTextures(1, &gl_texID);
		//bind to the new texture ID
		glBindTexture(GL_TEXTURE_2D, gl_texID);

		//store the texture data for OpenGL use
		glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height,
			border, image_format, GL_UNSIGNED_BYTE, bits);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//Free FreeImage's copy of the data
		FreeImage_Unload(dib);

		//return success
		//Make sure to also save the value..
		p->SpriteTable[filename] = gl_texID;
		return gl_texID;
	}

	bool UnloadTexture(const unsigned int gl_texID)
	{
		//Makes sure Texture isn't 0/null
		if(gl_texID != 0)
		{
			//Tells Opengl to get rid of it
			glDeleteTextures(1, &gl_texID);
			return true;
		}

		return false;
	}

	void DrawLine(float x, float y, float endX, float endY, char R, char G, char B, char A)
	{
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, 0);
		glColor4f(R, G, B, A);

		glBegin(GL_LINES);
			glVertex2f(x, y); 
			glVertex2f(endX, endY);
		glEnd();

		glPopMatrix();
	}

	void DrawGrid(float cellsize, float gridsize)
	{
		for(int i = 0; i < gridsize; i++)
		{
			Functions::DrawLine(0, i * cellsize ,  cellsize *gridsize, i * cellsize,1,1,1,1);
			Functions::DrawLine(i * cellsize, 0 , i * cellsize, cellsize * gridsize,1,1,1,1);
		}
	}

	void DrawGridat(float cellsize, float gridsizew, float gidsizeh, float x, float y)
	{
		for(int i = 0; i < gidsizeh; i++)
		{
			Functions::DrawLine(0 + x, (i * cellsize) + y ,  (cellsize * gridsizew)  + x, (i * cellsize) + y,1,1,1,1);
		}

		for(int r = 0; r < gridsizew; r++)
		{
			Functions::DrawLine((r * cellsize) + x , 0 + y , (r * cellsize)+ x , (cellsize * gidsizeh)+y ,1,1,1,1);
		}

		Functions::DrawLine( x ,  y + (cellsize * gidsizeh) ,(cellsize * gridsizew) + x, (cellsize * gidsizeh)+y ,1,1,1,1);
		Functions::DrawLine((cellsize * gridsizew) + x ,(cellsize * gidsizeh)+y,(cellsize * gridsizew) + x, y ,1,1,1,1);
	}

	void DrawTriangle(unsigned int sprite, float X, float Y, float Z, 
		float Width, float Height, Color color, float Angle)
	{
		glPushMatrix();
		glTranslatef(X, Y, Z);
		glRotatef(Angle,0,0,1);
		glScalef(Width, Height, 1);
		glColor4f(color.R, color.G, color.B, color.A);
		glBindTexture(GL_TEXTURE_2D, sprite);
		glBegin(GL_TRIANGLES);

			glTexCoord2f(0,0.5);
			glVertex2f(0, 0.5);
			glTexCoord2f(0,1);
			glVertex2f(-0.5, -0.5);
			glTexCoord2f(1,1);
			glVertex2f(0.5, -0.5);

		glEnd();
		glPopMatrix();
	}

	void DrawRect(unsigned int sprite, float X, float Y, 
		float Width, float Height, Color color, float Angle)
	{
		glPushMatrix();
		//gluLookAt(1024/2, 768/2, 500, 1024/2, 768/2,0,0,1,0);
		glTranslatef(X, Y, 1);
		glRotatef(Angle,0,0,1);
		glScalef(Width, Height, 1);
		glColor4f(color.R, color.G, color.B, color.A);
		glBindTexture(GL_TEXTURE_2D, sprite);
		glBegin(GL_QUADS);

		// Y goes up:
			//glTexCoord2f(0,0);
			//glVertex2f(0, 0);

			//glTexCoord2f(0,1);
			//glVertex2f(0, 1);

			//glTexCoord2f(1,1);
			//glVertex2f(1, 1);

			//glTexCoord2f(1,0);
			//glVertex2f(1,0);


		// Y goes down:
			glTexCoord2f(0, 1);
			glVertex2f(0, 0);
			
			glTexCoord2f(0, 0);
			glVertex2f(0, 1);

			glTexCoord2f(1, 0);
			glVertex2f(1, 1);

			glTexCoord2f(1, 1);
			glVertex2f(1, 0);
			
		glEnd();

		glPopMatrix();
	}

	void DrawRectCent(unsigned int sprite, float X, float Y, 
		float Width, float Height, Color color, float Angle)
	{
		glPushMatrix();
		//gluLookAt(1024/2, 768/2, 500, 1024/2, 768/2,0,0,1,0);
		glTranslatef(X, Y, 1);
		glRotatef(Angle,0,0,1);
		glScalef(Width, Height, 1);
		glBindTexture(GL_TEXTURE_2D, sprite);
		glColor4f(color.R, color.G, color.B, color.A);

		glBegin(GL_QUADS);

		// Broke, i'll fix later.
			glTexCoord2f(0,0);
			glVertex2f(-0.5, 0.5);
			glTexCoord2f(0,1);
			glVertex2f(-0.5, -0.5);
			glTexCoord2f(1,1);
			glVertex2f(0.5, -0.5);
			glTexCoord2f(1,0);
			glVertex2f(0.5,0.5);
			
		glEnd();

		glPopMatrix();
	}

	void DrawIsoView(unsigned int sprite, float X, float Y, 
		float Width, float Height, Color color, float Angle)
	{
		glPushMatrix();
		//gluLookAt(1024/2, 768/2, 500, 1024/2, 768/2,0,0,1,0);
		glTranslatef(X, Y, 1);
		glRotatef(Angle,0,0,1);
		glScalef(Width, Height , 1);
		glColor4f(color.R, color.G, color.B, color.A);
		glBindTexture(GL_TEXTURE_2D, sprite);
		glBegin(GL_QUADS);


		// Y goes up:
			//glTexCoord2f(0,0);
			//glVertex2f(0, 0);

			//glTexCoord2f(0,1);
			//glVertex2f(0, 1);

			//glTexCoord2f(1,1);
			//glVertex2f(1, 1);

			//glTexCoord2f(1,0);
			//glVertex2f(1,0);


		// Y goes down:
			glTexCoord2f(0, 1);
			glVertex2f(0.5, 0);
			
			glTexCoord2f(0, 0);
			glVertex2f(0, 0.5);

			glTexCoord2f(1, 0);
			glVertex2f(0.5, 1);

			glTexCoord2f(1, 1);
			glVertex2f(1, 0.5);
			
		glEnd();

		glPopMatrix();
	}

	bool AABBCollision(Vector2 vPos, Vector2 Vec2, float Width, 
		float Width2, float Height, float Height2)
	{

		if ((vPos.Y + Height) > Vec2.Y && vPos.Y < (Vec2.Y + Height2) && 
				(vPos.X + Width) > Vec2.X && vPos.X < (Vec2.X + Width2))
			return true;
		else
			return false;
	}
	
	bool MouseRectCollision(float MouseX, float MouseY,
		float RectX, float RectY, float RectWidth, float RectHeight)
	{
		if (MouseX > RectX && MouseX < RectX + RectWidth && 
			MouseY > RectY && MouseY < RectY + RectHeight)
			return true;
		else
			return false;
	}

	// Rotated Rectangles Collision Detection, Oren Becker, 2001
	bool CheckRotRectCollision(_RotRect * rr1, _RotRect * rr2)
	{
		float rr1ang = rr1->ang * M_PI/180.0f;
		float rr2ang = rr2->ang * M_PI/180.0f;

		Vector2 A, B,   // vertices of the rotated rr2
		C,      // center of rr2
		BL, TR; // vertices of rr2 (bottom-left, top-right)

		float ang = rr1ang - rr2ang, // orientation of rotated rr1
		cosa = cos(ang),           // precalculated trigonometic -
		sina = sin(ang);           // - values for repeated use

		float t, x, a;      // temporary variables for various uses
		float dx;           // deltaX for linear equations
		float ext1, ext2;   // min/max vertical values

		// move rr2 to make rr1 cannonic
		C = rr2->C;
		C -= rr1->C;

		// rotate rr2 clockwise by rr2->ang to make rr2 axis-aligned
		C.RotateVector2DClockwise(rr2ang);

		// calculate vertices of (moved and axis-aligned := 'ma') rr2
		BL = TR = C;

		BL -= rr2->S/2;
		TR += rr2->S/2;

		// calculate vertices of (rotated := 'r') rr1
		A.X = -(rr1->S.Y / 2) * sina; 
		B.X = A.X; 
		t = (rr1->S.X / 2) * cosa;
		A.X += t; 
		B.X -= t;
		A.Y = (rr1->S.Y / 2) * cosa;
		B.Y = A.Y; 
		t = (rr1->S.X / 2) * sina;
		A.Y += t; 
		B.Y -= t;

		t = sina*cosa;

		// verify that A is vertical min/max, B is horizontal min/max
		if (t < 0)
		{
			t = A.X; A.X = B.X; B.X = t;
			t = A.Y; A.Y = B.Y; B.Y = t;
		}

		// verify that B is horizontal minimum (leftest-vertex)
		if (sina < 0) { B.X = -B.X; B.Y = -B.Y; }

		// if rr2(ma) isn't in the horizontal range of
		// colliding with rr1(r), collision is impossible
		if (B.X > TR.X || B.X > -BL.X) return false;

		// if rr1(r) is axis-aligned, vertical min/max are easy to get
		if (t == 0) {ext1 = A.Y; ext2 = -ext1; }
		// else, find vertical min/max in the range [BL.x, TR.x]
		else
		{
			x = BL.X-A.X; a = TR.X-A.X;
			ext1 = A.Y;
			// if the first vertical min/max isn't in (BL.x, TR.x), then
			// find the vertical min/max on BL.x or on TR.x
			if (a*x > 0)
			{
				dx = A.X;
				if (x < 0) { dx -= B.X; ext1 -= B.Y; x = a; }
				else       { dx += B.X; ext1 += B.Y; }

				ext1 *= x; ext1 /= dx; ext1 += A.Y;
			}
  
			x = BL.X+A.X; a = TR.X+A.X;
			ext2 = -A.Y;
			// if the second vertical min/max isn't in (BL.x, TR.x), then
			// find the local vertical min/max on BL.x or on TR.x
			if (a*x > 0)
			{
				dx = -A.X;
				if (x < 0) { dx -= B.X; ext2 -= B.Y; x = a; }
				else       { dx += B.X; ext2 += B.Y; }
				ext2 *= x; ext2 /= dx; ext2 -= A.Y;
			}
		}

		// check whether rr2(ma) is in the vertical range of colliding with rr1(r)
		// (for the horizontal range of rr2)
		return !((ext1 < BL.Y && ext2 < BL.Y) ||
		(ext1 > TR.Y && ext2 > TR.Y));
	}

	void SetColor(float R, float G, float B, float A, Color &color)
	{
		// Simple function to wrap setting colors
		color.R = R;
		color.G = G;
		color.B = B;
		color.A = A;
	}

	bool IsKeyDown(int letter)
	{
		return !!GetKeyState(letter);
	}

	bool IsKeyUp(int letter)
	{
		return GetKeyState(letter) == 0;
	}

	int GetMouseX()
	{
		GLWindow *p = GLWindow::getInstance();

		int x = p->GetMouseX();
 
		return x;
	}

	int GetMouseY()
	{
		GLWindow *p = GLWindow::getInstance();

		int y = p->GetMouseY();
 
		return y;
	}

}