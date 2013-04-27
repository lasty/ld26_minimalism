
#include <stdexcept>
using std::exception;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "game.h"


#ifdef __WIN32__
//sdl redefines main which screws a couple things up for me
#undef main
#endif

int main(int argc, char **argv)
{
	try
	{
		MinGame thegame;

		thegame.Run();

	}
	catch (exception &e)
	{
		cerr << "Exception caught:  " << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown Exception caught" << endl;
		return 2;
	}

	return 0;
}

