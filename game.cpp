
#include "game.h"

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;


MinGame::MinGame()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_CENTERED, 50, width, height, window_flags);

	glcontext = SDL_GL_CreateContext(window);

	auto glewstatus = glewInit();

	if (glewstatus != GLEW_OK)
	{
		throw runtime_error("Could not initialize GLEW opengl library");
	}
	
}


MinGame::~MinGame()
{
	SDL_GL_DeleteContext(glcontext);
	glcontext = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

}


void MinGame::ProcessEvent(SDL_Event &event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			running = false;
		break;
	}
}


void MinGame::Update(float dt)
{
}


void MinGame::Render()
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);  //#1a334d

	glClear(GL_COLOR_BUFFER_BIT);

}


void MinGame::Run()
{
	running = true;

	auto last_time = SDL_GetTicks();

	SDL_Event event;

	while (running)
	{
		while ( SDL_PollEvent(&event) )
		{
			ProcessEvent(event);
		}

		auto time = SDL_GetTicks() - last_time;
		float deltatime = time / 1000.0f;
		last_time = time;

		Update(deltatime);

		Render();

		SDL_GL_SwapWindow(window);
	}

	

}



