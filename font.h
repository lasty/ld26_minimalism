#ifndef __LD26_FONT_H_
#define __LD26_FONT_H_

#include "GL/glew.h"

#include <string>
using std::string;

#include "colour.h"

class Font
{
	public:


	Font(float zoom=1.0f);

	~Font();


	void DrawText(int x, int y, const string &txt, const Colour &fg);

	void DrawText(int x, int y, const string &txt, const Colour &fg, const Colour &bg);

	GLuint texid = 0;
	float xstep=0.0f;
	float ystep=0.0f;

	int tilesizex = 0;
	int tilesizey = 0;

	float zoom = 1.0f;
	bool smooth = false;
};

#endif
