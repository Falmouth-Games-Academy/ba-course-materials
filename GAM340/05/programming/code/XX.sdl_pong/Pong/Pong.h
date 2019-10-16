#pragma once
#include <SDL.h>
#include "Ball.h"
#include "Player.h"
#include "DebugPrinter.h"

class Pong
{
	private:
		Player ThePlayers[2];
		Ball TheBall;

		void DrawCourt(SDL_Renderer* renderer);
	public:
		
		int Score[2];
		bool Init(SDL_Renderer *renderer);
		bool Update();
		bool Draw(SDL_Renderer *renderer);
		bool Shutdown();

		DebugPrinter* debugPrinter;

	};