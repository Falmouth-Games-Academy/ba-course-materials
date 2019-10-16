//SDL2 flashing random color example
//Should work on iOS/Android/Mac/Windows/Linux

#include <SDL.h>
#undef  main

#include <stdlib.h> //rand()
#include "timer.h"

#include "Pong/Pong.h"
#include <list>

bool quitting = false;
float r = 0.0f;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

int SDLCALL watch(void *userdata, SDL_Event* event)
{

	if (event->type == SDL_APP_WILLENTERBACKGROUND)
	{
		quitting = true;
	}

	return 1;
}

int main(int argc, char *argv[]) {


	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_AddEventWatch(watch, NULL);

	Timer frameTimer, fpsTimer;

	Pong* myGame = new Pong();

	float elaspedTime = 0;
	float fpsTime = 0;

	if (myGame->Init(renderer) != false)
	{		
		frameTimer.Start();

		while (!quitting)
		{
			SDL_Event event;

			fpsTimer.Stop();
			fpsTime = fpsTimer.GetmS();
			fpsTimer.Start();
								
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quitting = true;
				}
			}

			myGame->Update();
			{				
				myGame->Draw(renderer);

				myGame->debugPrinter->Print(renderer, 10, 80, RGBATOCOLOR(255, 0, 0, 255), "%f %f %f", elaspedTime, fpsTime, 1000.0f/fpsTime);


				SDL_RenderPresent(renderer);
				
				frameTimer.Stop();
				elaspedTime = frameTimer.GetmS();
				

				if (elaspedTime < 17)
				{
					Sleep((DWORD)(17 - elaspedTime));					
				}
				
				frameTimer.Start();
			}
		}
	}

	enum State{State_1,State_2,State_3};

	State currentState = State_1;
	
	switch (currentState)
	{
		case State_1:
			//do this
			break;
		
		case State_2:
			//do that
			break;

		case State_3:
			//do the other
			break;
		default:
			throw "Unhandled state";
			break;

	}


	
	SDL_DelEventWatch(watch, NULL);
	SDL_DestroyWindow(window);
	SDL_Quit();
} //main