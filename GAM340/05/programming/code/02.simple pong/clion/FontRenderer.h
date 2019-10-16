//
// Created by gareth on 16/10/2019.
//

#pragma once

#include <SDL.h>

class FontRenderer
{
public:
    FontRenderer(SDL_Renderer* renderer,const char *font);

    void Print(SDL_Renderer* renderer,int x,int y,const char* text);
    void PrintScale(SDL_Renderer* renderer,int x,int y,const char* text, float s=1.0f);

private:
    SDL_Texture* texture;
};

