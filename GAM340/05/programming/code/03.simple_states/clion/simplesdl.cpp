#include <SDL.h>
#include <SDL_image.h>

#include <stdlib.h>
#include <stdio.h>

#undef  main

#include <stdlib.h> //rand()

#include "containers.h"
#include "FontRenderer.h"

#include "gamestates.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

FontRenderer* pFont;

int main(int argc, char *argv[])
{
	//Initialise IMG system, this allows us to load PNG files
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);

	//Initialise window & renderer
	window = NULL;
	renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return 0;
	}

	//create a window that is 800x600 pixels
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	pFont = new FontRenderer(renderer,"resources/font.bmp");
	
	Uint32 lastElapsedTime=0, fpsTimer=0;
	
	Uint32 elaspedTime = 0;
	Uint32 fpsTime = 0;

	SDL_Event event;
	bool quitting = false;

	StateMachine machine;

	machine.stateList = new StateMachine::State*[3];

    machine.stateList[0] = new State_0();
    machine.stateList[1] = new State_1();
    machine.stateList[2] = new State_2();

    machine.SetState(0);

	while (!quitting)
	{	
		fpsTime = SDL_GetTicks() - lastElapsedTime;
		lastElapsedTime = SDL_GetTicks();

		//Clear the screen before we draw to it
		//https://wiki.libsdl.org/SDL_RenderClear
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				{
					quitting = true;
				}
				break;


				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
					    case SDLK_1:
						    machine.SetState(0);
						break;

                        case SDLK_2:
                            machine.SetState(1);
                            break;

                        case SDLK_3:
                            machine.SetState(2);
                            break;



                        default:
						    break;
					}
					break;
				}
				break;

			    case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_q:
                        case SDLK_a:

                            break;

                        case SDLK_p:
                        case SDLK_l:
                            break;

                        default:
                            break;
                    }
                    break;
			        break;
			}
		}

        machine.Update();
		machine.Draw(renderer);

		//This uses the window title to display frame performance information
		{
			char temp[255];

			sprintf(temp, "Frame Time:%.3f  (%3.0f FPS)", (float)(fpsTime), 1000.0f/fpsTime);
	
			SDL_SetWindowTitle(window, temp);

			pFont->Print(renderer,10,10,temp);
		}
			
		//End of frame rendering
		SDL_RenderPresent(renderer);							
				
		//Sleep the app					
		if (elaspedTime < 15)
		{
			SDL_Delay(15 - elaspedTime);
		}							
	}
	
	quit:
		//On end of application, close down resources and exit
		SDL_DestroyWindow(window);
		SDL_Quit();

		window = NULL;
		renderer = NULL;

	return 0;
}