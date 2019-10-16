#include "DebugPrinter.h"
#include "bitmap.h"

#include <windows.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int RGBATOCOLOR(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return b | (g << 8) | (r << 16) | (a << 24);
}

void COLORTORGBA(int col, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a)
{
	r = (col & 0x00ff0000) >> 16;
	g = (col & 0x0000ff00) >> 8;
	b = (col & 0x000000ff);
	a = (col & 0xff000000) >> 24;
}


int RGBTOCOLOR(unsigned char r, unsigned char g, unsigned char b)
{
	return RGBATOCOLOR(r, g, b, 255);
}



void DebugPrinter::Init(SDL_Renderer* renderer)
{
	Bitmap image;

	if (image.Load("resources/font.bmp") != false)
	{
		Bitmap target(image.GetWidth(), image.GetHeight(), 32);

		debugFont = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, target.GetWidth(), target.GetHeight());

		unsigned int* pixels = nullptr;
		int pitch = 0;

		SDL_LockTexture(debugFont, NULL, (void**)&pixels, &pitch);

		for (unsigned int y = 0; y < image.GetHeight(); y++)
		{
			for (unsigned int x = 0; x < image.GetWidth(); x++)
			{
				unsigned char *pixel = image.GetPixel(x, y);

				unsigned char t[4];
				t[2] = *pixel;
				t[1] = *(pixel + 1);
				t[0] = *(pixel + 2);
				t[3] = max(t[0], max(t[1], t[2]));

				if (t[3] > 0)
				{
					t[3] = 255;
				}

				target.SetPixel(x, image.GetHeight() - 1 - y, t);

				pixels[((image.GetHeight() - 1 - y)*image.GetWidth()) + x] = RGBATOCOLOR(t[0], t[1], t[2], t[3]);
			}
		}

		SDL_UnlockTexture(debugFont);
	}

	SetJustification(Justifiy_Left);
	SetScale(1, 1);

}

void DebugPrinter::SetScale(float w, float h)
{
	fontScaleX = w;
	fontScaleY = h;
}

void DebugPrinter::SetJustification(Justification just)
{
	currentJust = just;
}

int DebugPrinter::calculateOffset(const char *buffer)
{
	const char* p = buffer;
	int count = 0;

	while ((*p != NULL) && (*p != '\n'))
	{
		p++;
		count++;
	}
	
	switch (currentJust)
	{
		case Justifiy_Left:
			return 0;
		break;

		case Justifiy_Centre:						
			return -(int)((count * 8 * fontScaleX)/2);
		break;

	case Justifiy_Right:
		return -(int)(count * 8 * fontScaleX);
		break;
	}

	return 0;
}

void DebugPrinter::Print(SDL_Renderer* renderer, int x, int y, int colour, char* fmt, ...)
{
	char buffer[4096];

	va_list args;

	va_start(args, fmt);

	vsprintf(buffer, fmt, args);

	SDL_Rect src, dest;

	unsigned char r, g, b, a;

	COLORTORGBA(colour, r, g, b, a);
	
	SDL_SetTextureBlendMode(debugFont, SDL_BLENDMODE_BLEND);
	SDL_SetTextureColorMod(debugFont, r, g, b);
	
	src.w = 16; src.h = 16;

	dest.x = x+ calculateOffset(buffer); 
	dest.y = y; 
	dest.w = (int)(8 * fontScaleX); 
	dest.h = (int)(8 * fontScaleY);

	for (unsigned int i = 0; i < strlen(buffer); i++)
	{
		switch (buffer[i])
		{
		case '\n':			
			dest.x = x+ calculateOffset(&buffer[i]);
			dest.y += (int)(8 * fontScaleY);
			break;

		case ' ':
			dest.x += (int)(8 * fontScaleX);
			break;

		default:
			int ch = buffer[i];
			src.x = (ch % 16) * 16; src.y = (ch / 16) * 16;
			SDL_RenderCopy(renderer, debugFont, &src, &dest);

			dest.x += (int)(8 * fontScaleX);

			break;
		}
	}

}
