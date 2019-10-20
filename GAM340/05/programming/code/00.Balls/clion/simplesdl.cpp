#include <SDL.h>
#include <SDL_image.h>

#include <stdlib.h>
#include <stdio.h>

#undef  main

#include <stdlib.h> //rand()

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")

class Colour : public SDL_Color
{
public:
    Colour(){}
    Colour(Uint8 r, Uint8 g, Uint8 b, Uint8 a =255)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};

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

class Vector2 : public SDL_FPoint
{
public:
    Vector2(){}
    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

class BallInstance
{
    public:
        Rect rect;
        Vector2 velocity;
        Colour colour;

        void Update()
        {
            if(rect.x < 0)
            {
                velocity.x = - velocity.x;
            }

            if(rect.y < 0)
            {
                velocity.y = - velocity.y;
            }

            if(rect.x + rect.w > 800)
            {
                velocity.x = - velocity.x;
            }

            if(rect.y +rect.h > 600)
            {
                velocity.y = - velocity.y;
            }

            rect.x += velocity.x;
            rect.y += velocity.y;
        }
};

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;


int main(int argc, char *argv[])
{
    BallInstance* myBalls = new BallInstance[100];
    int ballCount = 1;


    for(int i=0;i<100;i++)
    {
        myBalls[i].rect.x = (rand()%(800-200)) +100;
        myBalls[i].rect.y = (rand()%(600-200)) +100;

        myBalls[i].rect.w = (rand()%(128)) +16;
        myBalls[i].rect.h = myBalls[i].rect.w;

        myBalls[i].velocity.x = (((rand()%200)-100) /100.0f) *5.0f;
        myBalls[i].velocity.y = (((rand()%200)-100) /100.0f) *5.0f;

        myBalls[i].colour.r = rand()%256;
        myBalls[i].colour.g = rand()%256;
        myBalls[i].colour.b = rand()%256;
        myBalls[i].colour.r = 255;
    }

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

	//load a bitmap using the IMG library
	SDL_Surface* srcImage = IMG_Load("resources/ball.png");

	if (srcImage == NULL)
	{
		SDL_Log("SDL_Surface: can't load image\n");
		return 0;
	}

	SDL_Texture* ballTexture;

	//convert the
    ballTexture = SDL_CreateTextureFromSurface(renderer, srcImage);
	
	if (ballTexture == NULL)
	{
		SDL_Log("SDL_Texture: can't create texture\n");
		return 0;
	}

	SDL_SetTextureBlendMode(ballTexture, SDL_BLENDMODE_BLEND);

	
	
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
					case SDLK_LEFT:
					    if(ballCount > 0)
						    ballCount--;
						break;
					case SDLK_RIGHT:
                        if(ballCount < 100)
                            ballCount++;
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
                        printf("not left\n");
						break;
					case SDLK_RIGHT:
						break;
					default:
						break;
					}
				}
				break;
			}
		}

        for(int i=0;i<ballCount;i++)
        {
            myBalls[i].Update();
            SDL_SetTextureColorMod(ballTexture,myBalls[i].colour.r,myBalls[i].colour.g, myBalls[i].colour.b);
            SDL_RenderCopy(renderer, ballTexture, NULL, &myBalls[i].rect);
        }

		//This uses the window title to display frame performance information
		{
			char temp[255];

			sprintf(temp, "Frame Time:%.3f  (%3.0f FPS)", (float)(fpsTime), 1000.0f/fpsTime);
	
			SDL_SetWindowTitle(window, temp);
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