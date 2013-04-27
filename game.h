
#include "SDL.h"

#include "GL/glew.h"

#include <string>
using std::string;

class MinGame
{
public:
	MinGame();
	~MinGame();

	void Run();
	void ProcessEvent(SDL_Event &e);

	void Update(float dt);

	void Render();

	unsigned width = 640;
	unsigned height = 480;
	string window_title = "Ludum Dare 26 - Minimalism - Lasty";
	unsigned window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;


	SDL_Window *window = nullptr;
	SDL_GLContext glcontext = nullptr;
	bool running = false;



};


