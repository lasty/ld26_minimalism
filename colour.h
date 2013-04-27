#ifndef __LD26_COLOUR_H_
#define __LD26_COLOUR_H_

class Colour
{
	public:
	float r,g,b,a;

	Colour(float r, float g, float b, float a=1.0f)
	: r(r), g(g), b(b), a(a)
	{
	}
};

#endif
