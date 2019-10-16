#pragma once
#include <stdlib.h>
#include <windows.h>
#include <SDL.h>
#include "DebugPrinter.h"

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

class AudioEffect
{
};

typedef AudioEffect* HEFFECT;


class GameShell
{
	public:
		static int RGBATOCOLOR(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		static int RGBTOCOLOR(unsigned char r, unsigned char g, unsigned char b);
		static void COLORTORGBA(int col, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a);
		static void DrawRect(int x, int y, int w, int h, int c);
		static void Print(int x, int y, int colour, char* fmt, ...);

		static void DebugPrint(int x, int y, char* fmt, ...);

		static HEFFECT LoadWAV(const char* filename);

		virtual bool Init();
		virtual bool Update();
		virtual bool Draw();

		virtual bool Shutdown();
		
		static SDL_Window *window;
		static SDL_Renderer *renderer;
		static DebugPrinter* debugPrinter;

};