#pragma once
#include <SDL.h>

int RGBATOCOLOR(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int RGBTOCOLOR(unsigned char r, unsigned char g, unsigned char b);
void COLORTORGBA(int col, unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a);

class DebugPrinter
{
public:
	void Init(SDL_Renderer* renderer);
	void SetScale(float w, float h);

	enum Justification { Justifiy_Left, Justifiy_Right, Justifiy_Centre };
	void SetJustification(Justification just);
	void Print(SDL_Renderer* renderer,int x, int y, int colour, char* fmt, ...);

	

private:
	int calculateOffset(const char *buffer);

	SDL_Texture*    debugFont;

	float fontScaleX, fontScaleY;
	Justification currentJust;
};
