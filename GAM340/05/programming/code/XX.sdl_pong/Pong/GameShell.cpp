#include "GameShell.h"
#include "Timer.h"

#include <assert.h>
#include <math.h>

#include "bitmap.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


//HGE*		GameShell::hge = NULL;

SDL_Window* GameShell::window;
SDL_Renderer* GameShell::renderer;
DebugPrinter* GameShell::debugPrinter;



//hgeFont* debugFont = NULL;

int GameShell::RGBATOCOLOR(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return b | (g<<8) | (r<<16) | (a<<24);
}

void GameShell::COLORTORGBA(int col, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a)
{
	r = (col & 0x00ff0000) >> 16;
	g = (col & 0x0000ff00) >> 8;
	b = (col & 0x000000ff);
	a = (col & 0xff000000) >> 24;
}


int GameShell::RGBTOCOLOR(unsigned char r, unsigned char g, unsigned char b)
{
	return RGBATOCOLOR(r,g,b,255);
}

void GameShell::DrawRect(int x, int y, int w, int h, int c)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	unsigned char r, g, b, a;

	COLORTORGBA(c, r, g, b, a);

	SDL_SetRenderDrawColor(GameShell::renderer, r,g,b,a);
	SDL_RenderFillRect(GameShell::renderer, &rect);
}

HEFFECT GameShell::LoadWAV(const char* filename)
{
	return new AudioEffect();
}

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void GameShell::Print(int x, int y, int colour, char* fmt, ...)
{
	char buffer[4096];

	va_list args;    

	va_start( args, fmt );

	vsprintf( buffer, fmt, args );

	debugPrinter->Print(x, y, colour, buffer);
}

void GameShell::DebugPrint(int x, int y, char* fmt, ...)
{

	char buffer[4096];

	va_list args;    

	va_start( args, fmt );

	vsprintf( buffer, fmt, args );

	debugPrinter->Print(x,y,RGBTOCOLOR(255,255,255),buffer);

}


int SDLCALL watch(void *userdata, SDL_Event* event) 
{

	if (event->type == SDL_APP_WILLENTERBACKGROUND) 
	{
		//quitting = true;
	}

	return 1;
}


bool GameShell::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) 
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_AddEventWatch(watch, NULL);

	debugPrinter = new DebugPrinter();
	debugPrinter->Init();
	
	return true;
}

bool GameShell::Update()
{
	return true;
}


bool GameShell::Draw()
{
	return true;
}


bool GameShell::Shutdown()
{
	SDL_DelEventWatch(watch, NULL);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return true;
}
