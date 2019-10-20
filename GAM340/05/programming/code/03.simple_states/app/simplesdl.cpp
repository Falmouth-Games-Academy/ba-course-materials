#include <SDL.h>
#include <SDL_image.h>

#include <stdlib.h>
#include <stdio.h>

#include <windows.h>

#undef  main

#include <stdlib.h> //rand()

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")

class Rect : public SDL_Rect
{
public:
	Rect() {}
	Rect(int x, int y, int w, int h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

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
		return false;
	}

	//create a window that is 800x600 pixels
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//load a bitmap using the IMG library
	SDL_Surface* srcImage = IMG_Load("resources/font.bmp");

	if (srcImage == NULL)
	{
		SDL_Log("SDL_Surface: can't load image\n");
		goto quit;
	}

	srcImage = SDL_ConvertSurfaceFormat(srcImage, SDL_PIXELFORMAT_ARGB8888, 0);

	unsigned char* p = (unsigned char*)srcImage->pixels;
	for (int y = 0; y < srcImage->h; y++)
	{
		for (int x = 0; x < srcImage->w; x++)
		{
			unsigned char alpha = ((*p > 0) || (*(p + 1) > 0) || (*(p + 2) > 0)) ? 255 : 0;

			*p = *p; // B
			p++;
			*p = *p; // G
			p++;
			*p = *p; // R
			p++;
			*p = alpha; // A
			p++;
		}
	}

	SDL_Texture* fontTexture;
	
	//convert the
	fontTexture = SDL_CreateTextureFromSurface(renderer, srcImage);
	
	if (fontTexture == NULL)
	{
		SDL_Log("SDL_Texture: can't create texture\n");
		goto quit;
	}

	SDL_SetTextureBlendMode(fontTexture, SDL_BLENDMODE_BLEND);

	
	
	Uint32 lastElapsedTime=0, fpsTimer=0;
	
	Uint32 elaspedTime = 0;
	Uint32 fpsTime = 0;

	SDL_Event event;
	bool quitting = false;

	signed int ball_xvel = 0;
	signed int ball_yvel = 0;

	signed int ballX = 800/2;
	signed int ballY = 600/2;

	//The main application loop
	//This uses SDL_GetTicks() to record elapsed time and pause the application with Sleep to keep it running at 60fps rather than thousands of fps

	while (!quitting)
	{	
		fpsTime = SDL_GetTicks() - lastElapsedTime;
		lastElapsedTime = SDL_GetTicks();

		//Clear the screen before we draw to it
		//https://wiki.libsdl.org/SDL_RenderClear
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);

		// SDL uses events to communicate with the application
		// In this instance, the app is just responding to SDL_QUIT messages which occur when the application is closed
		// to close the app down, either press the X icon on the window or get you program to generation an SDL_QUIT event internally
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				{
					quitting = true;
				}
				break;

				/* Look for a keypress */
				//https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html
				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_LEFT:
						ball_xvel = -1;
						break;
					case SDLK_RIGHT:
						ball_xvel = 1;
						break;
					case SDLK_UP:
						ball_yvel = -1;
						break;
					case SDLK_DOWN:
						ball_yvel = 1;
						break;
					default:
						break;
					}
					break;
				}

				case SDL_KEYUP:
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_LEFT:
						if (ball_xvel < 0)
							ball_xvel = 0;
						break;
					case SDLK_RIGHT:
						if (ball_xvel > 0)
							ball_xvel = 0;
						break;
					case SDLK_UP:
						if (ball_yvel < 0)
							ball_yvel = 0;
						break;
					case SDLK_DOWN:
						if (ball_yvel > 0)
							ball_yvel = 0;
						break;
					default:
						break;
					}
				}
				break;
			}
		}

		ballX += ball_xvel;
		ballY += ball_yvel;

		//draw the ball using SDL_RenderCopy
		//this requires a rectangle of the ball's position and size (for scalability)		
		SDL_Rect dest;

		dest.x = ballX;
		dest.y = ballY;
		dest.w = 256;
		dest.h = 256;
					
		SDL_RenderCopy(renderer, fontTexture, NULL, &dest);

		//This uses the window title to display frame performance information
		{
			char temp[255];

			sprintf(temp, "Frame Time:%.3f  (%3.0f FPS)", (float)(fpsTime), 1000.0f/fpsTime);
	
			SDL_SetWindowTitle(window, temp);
		}
			
		//End of frame rendering
		SDL_RenderPresent(renderer);							
				
		//Sleep the app					
		if (elaspedTime < 16)
		{
			Sleep(16 - elaspedTime);					
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