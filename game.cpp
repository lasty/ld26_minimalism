
#include "game.h"

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;


GameBase::GameBase()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, 50, width, height, window_flags);

	glcontext = SDL_GL_CreateContext(window);

	auto glewstatus = glewInit();

	if (glewstatus != GLEW_OK)
	{
		throw runtime_error("Could not initialize GLEW opengl library");
	}
	
	Resize(width, height);
}


GameBase::~GameBase()
{
	SDL_GL_DeleteContext(glcontext);
	glcontext = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

}


void GameBase::ProcessEvent(SDL_Event &event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			running = false;
		break;
	}
}


void GameBase::Update(float dt)
{
}


void GameBase::Render()
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);  //#1a334d

	glClear(GL_COLOR_BUFFER_BIT);

}

void GameBase::Resize(int newwidth, int newheight)
{
	width = newwidth;
	height = newheight;

	cout << "new width = " << width << "  height = " << height << endl;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height,  -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}


void GameBase::Run()
{
	running = true;

	auto last_time = SDL_GetTicks();

	SDL_Event event;

	while (running)
	{
		while ( SDL_PollEvent(&event) )
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			else
			{
				ProcessEvent(event);
			}
		}

		auto time = SDL_GetTicks() - last_time;
		float deltatime = time / 1000.0f;
		last_time = time;

		Update(deltatime);

		Render();

		SDL_GL_SwapWindow(window);
	}
}



MinGame::MinGame()
{

}

MinGame::~MinGame()
{

}


void MinGame::Render()
{
	GameBase::Render();

	glDisable(GL_TEXTURE_2D);

/*
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(1,1,0);

	glVertex3f(1,0,0);
	glVertex3f(0,1,0);

	glVertex3f(0,0,0);
	glVertex3f(512, 512, 0);
	glVertex3f(512,0,0);
	glVertex3f(0, 512, 0);
	glEnd();
*/

	thefont.DrawText(1,10, "HI, 1234567890\nTHIS IS COOL SHIT!\nHello, World!");


	thefont.DrawText(0,20, "0,10 Hello, World! @");
}

