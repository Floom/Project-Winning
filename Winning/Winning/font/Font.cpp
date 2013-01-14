#include "Font.h"
#include <Windows.h>
#include <misc\Functions.h>


using namespace Functions;
using namespace std;

Font::Font()
{
}
Font::~Font()
{
	
}

GLvoid Font::BuildFont(const char string[], float w, float h)								// Build Our Bitmap Font
{
	HFONT	font;										// Windows Font ID
	HFONT	oldfont;									// Used For Good House Keeping

	HDC hDC = wglGetCurrentDC();
	base = glGenLists(96);	// Storage For 96 Characters

	font = CreateFont(	h,							// Height Of Font
						w,								// Width Of Font
						0,								// Angle Of Escapement
						0,								// Orientation Angle
						FW_BOLD,						// Font Weight
						FALSE,							// Italic
						FALSE,							// Underline
						FALSE,							// Strikeout
						ANSI_CHARSET,					// Character Set Identifier
						OUT_TT_PRECIS,					// Output Precision
						CLIP_DEFAULT_PRECIS,			// Clipping Precision
						ANTIALIASED_QUALITY,			// Output Quality
						FF_DONTCARE|DEFAULT_PITCH,		// Family And Pitch
						string);					// Font Name

	oldfont = (HFONT)SelectObject(hDC, font);           // Selects The Font We Want
	wglUseFontBitmaps(hDC, 32, 96, base);				// Builds 96 Characters Starting At Character 32
	SelectObject(hDC, oldfont);							// Selects The Font We Want
	DeleteObject(font);									// Delete The Font
}

GLvoid Font::KillFont(GLvoid)									// Delete The Font List
{
	glDeleteLists(base, 96);							// Delete All 96 Characters
}

GLvoid Font::glPrint(float x, float y, float R, float G, float B, float A, const char *fmt, ...)				// Custom GL "Print" Routine
{
	glPushMatrix();
	char text[256];								// Holds Our String
	va_list	ap;										// Pointer To List Of Arguments

	if (fmt == NULL)									// If There's No Text
		return;											// Do Nothing

	va_start(ap, fmt);									// Parses The String For Variables
	    vsprintf(text, fmt, ap);						// And Converts Symbols To Actual Numbers
	va_end(ap);											// Results Are Stored In Text
	
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glColor4f(R,G,B,A);
	glRasterPos2f(x,y);

	
	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
	glListBase(base - 32);								// Sets The Base Character to 32
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();										// Pops The Display List Bits

	glPopMatrix();
}

GLvoid Font::glPrint(float x, float y, float R, float G, float B, float A, string str, ...)				// Custom GL "Print" Routine
{
	glPushMatrix();
	char text[256];								// Holds Our String
	char *fmt;
	fmt = new char [str.size()+1];
	strcpy (fmt, str.c_str());

	va_list	ap;										// Pointer To List Of Arguments

	if (fmt == NULL)									// If There's No Text
		return;											// Do Nothing

	va_start(ap, fmt);									// Parses The String For Variables
	    vsprintf(text, fmt, ap);						// And Converts Symbols To Actual Numbers
	va_end(ap);											// Results Are Stored In Text
	
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glColor4f(R,G,B,A);
	glRasterPos2f(x,y);

	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
	glListBase(base - 32);								// Sets The Base Character to 32
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();										// Pops The Display List Bits
	
	glPopMatrix();
}



//GLvoid Font::glInput(int x, int y, float R, float G, float B, float A, string &str, GLWindow *p)
//{
//	for(int i = 32; i <= 126; i++)
//	{
//		if(p->KeyPressed(i))
//		{
//			if (p->KeyPressed(VK_LSHIFT))
//			{
//				str.push_back(i - 32);				
//			}
//			else
//			{
//				str.push_back(i);				
//			}
//		}
//		if(p->KeyPressed(VK_BACK))
//		{
//			if (str.length() > 0 )
//				str.erase(str.end() - 1);			
//		}		
//	}
//
//	glPrint(x,y,R,G,B,A,str);
//
//}
