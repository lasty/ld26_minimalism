
#include "GL/glew.h"

#include <string>
using std::string;

class Font
{
	public:


	Font();

	~Font();


	void DrawText(int x, int y, const string &txt);


	GLuint texid = 0;
	float xstep=0.0f;
	float ystep=0.0f;

	int tilesizex = 0;
	int tilesizey = 0;

};

