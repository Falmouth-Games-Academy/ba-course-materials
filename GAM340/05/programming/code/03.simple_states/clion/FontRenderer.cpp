//
// Created by gareth on 16/10/2019.
//

#include "FontRenderer.h"
#include <SDL_image.h>

FontRenderer::FontRenderer(SDL_Renderer* renderer, const char *font)
{
    SDL_Surface* srcImage = IMG_Load(font);

    if (srcImage == NULL)
    {
        SDL_Log("SDL_Surface: can't load image\n");
        return;
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

    //convert the
    this->texture = SDL_CreateTextureFromSurface(renderer, srcImage);

    if (this->texture == NULL)
    {
        SDL_Log("SDL_Texture: can't create texture\n");
        return;
    }

    SDL_SetTextureBlendMode(this->texture, SDL_BLENDMODE_BLEND);
}



void FontRenderer::Print(SDL_Renderer* renderer ,int x,int y,const char* text)
{
    const char*p = text;

    while(*p != NULL)
    {
        SDL_Rect src;
        SDL_Rect dest;

        src.x = ((*p)%16)*16;
        src.y = ((*p)/16)*16;
        src.w = 16;
        src.h = 16;

        dest.x = x;
        dest.y = y;
        dest.w = 16;
        dest.h = 16;

        SDL_RenderCopy(renderer, texture, &src, &dest);

        x += 16;
        p++;
    }
}

void FontRenderer::PrintScale(SDL_Renderer* renderer,int x,int y,const char* text, float s)
{
    const char*p = text;


    while(*p != NULL)
    {
        SDL_Rect src;
        SDL_Rect dest;

        src.x = ((*p)%16)*16;
        src.y = ((*p)/16)*16;
        src.w = 16;
        src.h = 16;

        dest.x = x;
        dest.y = y;
        dest.w = 16*s;
        dest.h = 16*s;

        SDL_RenderCopy(renderer, texture, &src, &dest);

        x += 16*s;
        p++;
    }
}
