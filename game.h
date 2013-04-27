
#include "SDL.h"

#include "GL/glew.h"

#include <string>
using std::string;

#include "font.h"


class GameBase
{
public:
	GameBase();
	virtual ~GameBase();

	void Run();
	virtual void ProcessEvent(SDL_Event &e);

	virtual void Update(float dt);

	virtual void Render();

	virtual void Resize(int newwidth, int newheight);

	unsigned width = 640;
	unsigned height = 480;
	string window_title = "Ludum Dare 26 - Minimalism - Lasty";
	unsigned window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;


	SDL_Window *window = nullptr;
	SDL_GLContext glcontext = nullptr;
	bool running = false;
};


class MinGame : public GameBase
{
	public:
	MinGame();
	virtual ~MinGame();

	void Render();

	Font thefont;
};

