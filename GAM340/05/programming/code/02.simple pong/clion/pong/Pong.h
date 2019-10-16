#pragma once
#include <SDL.h>
#include "Ball.h"
#include "Player.h"

class Pong
{
	private:

		Ball TheBall;

		void DrawCourt(SDL_Renderer* renderer);
	public:
        Player ThePlayers[2];
		
		int Score[2];
		bool Init(SDL_Renderer *renderer);
		bool Update();
		bool Draw(SDL_Renderer *renderer);
		bool Shutdown();
	};