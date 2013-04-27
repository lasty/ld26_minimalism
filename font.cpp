
#include "font.h"


#include "data/font.c"

#include <iostream>
using std::cout;
using std::endl;


Font::Font(float zoom)
:zoom(zoom)
{
	glGenTextures(1, &texid);

	glBindTexture(GL_TEXTURE_2D, texid);

	tilesizex = gimp_image.width / 16;
	tilesizey = gimp_image.height / 8;


	xstep = tilesizex / float(gimp_image.width);
	ystep = tilesizey / float(gimp_image.height);

	tilesizex *= zoom;
	tilesizey *= zoom;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gimp_image.width, gimp_image.height, 
		0, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image.pixel_data);

	if (smooth)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	glGenerateMipmap(GL_TEXTURE_2D);
}



Font::~Font()
{
	glDeleteTextures(1, &texid);
}


void Font::DrawText(int x, int y, const string &txt, const Colour &fg)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, texid);

	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	float x1 = x * tilesizex;
	float y1 = y * tilesizey;

	for (char ch : txt)
	{
		if (ch == '\n')
		{
			x1 = x * tilesizex;
			y1 -= tilesizey;
			continue;
		}
		else if (ch == ' ')
		{
			x1 += tilesizex;
			continue;
		}

		int tilex = ch % 16;
		int tiley = (ch - 32) / 16;

		glColor4f(fg.r, fg.g, fg.b, fg.a);

		glTexCoord2f(tilex * xstep, tiley * ystep);
		glVertex3f(x1, y1, 0.0f);

		glTexCoord2f((tilex+1) * xstep, tiley * ystep);
		glVertex3f(x1 + tilesizex-0, y1, 0.0f);

		glTexCoord2f((tilex+1) * xstep, (tiley+1) * ystep);
		glVertex3f(x1 + tilesizex-0, y1 - (tilesizey-0), 0.0f);

		glTexCoord2f(tilex * xstep, (tiley+1) * ystep);
		glVertex3f(x1 , y1 - (tilesizey-0), 0.0f);

		x1 += tilesizex;
	}

	glEnd();
}

void Font::DrawText(int x, int y, const string &txt, const Colour &fg, const Colour &bg)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, texid);

	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	float x1 = x * tilesizex;
	float y1 = y * tilesizey;

	for (char ch : txt)
	{
		if (ch == '\n')
		{
			x1 = x * tilesizex;
			y1 -= tilesizey;
			continue;
		}

		ch = 127; //solid colour

		int tilex = ch % 16;
		int tiley = (ch - 32) / 16;

		glColor4f(bg.r, bg.g, bg.b, bg.a);

		glTexCoord2f(tilex * xstep, tiley * ystep);
		glVertex3f(x1, y1, 0.0f);

		glTexCoord2f((tilex+1) * xstep, tiley * ystep);
		glVertex3f(x1 + tilesizex-0, y1, 0.0f);

		glTexCoord2f((tilex+1) * xstep, (tiley+1) * ystep);
		glVertex3f(x1 + tilesizex-0, y1 - (tilesizey-0), 0.0f);

		glTexCoord2f(tilex * xstep, (tiley+1) * ystep);
		glVertex3f(x1 , y1 - (tilesizey-0), 0.0f);

		x1 += tilesizex;
	}

	glEnd();

	DrawText(x,y, txt, fg);
}

