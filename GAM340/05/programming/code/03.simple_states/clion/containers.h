//
// Created by gareth on 16/10/2019.
//
#pragma once
#include <SDL.h>


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
