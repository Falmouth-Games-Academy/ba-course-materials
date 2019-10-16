#include "Pong.h"
#include <stdio.h>

bool Pong::Init(SDL_Renderer *renderer)
{
	ThePlayers[0].init();
	ThePlayers[0].SetSide(Player::Side_Left);

	ThePlayers[1].init();
	ThePlayers[1].SetSide(Player::Side_Right);

	TheBall.init();

	Score[0] = 0;
	Score[1] = 0;

	debugPrinter = new DebugPrinter();
	debugPrinter->Init(renderer);
		
	return true;
}

bool Pong::Update()
{
	if(TheBall.IsOutOfBounds() == true)
	{
		Player::Side serveTo = Player::Side_Undefined;
		if(TheBall.OutOfBoundsSide() == Player::Side_Left)
		{
			Score[1]++;
			serveTo = Player::Side_Left;
		}

		if(TheBall.OutOfBoundsSide() == Player::Side_Right)
		{
			Score[0]++;
			serveTo = Player::Side_Right;
		}

		TheBall.init();
		TheBall.ServeTo(serveTo);
	}
	else
	{
		if( ((TheBall.IsColliding(ThePlayers[0]) == true) && (TheBall.IsGoingTo() == Player::Side_Left))
		  ||((TheBall.IsColliding(ThePlayers[1]) == true) && (TheBall.IsGoingTo() == Player::Side_Right))
		  )
		{
			TheBall.PlayerReturns();
		}

		ThePlayers[0].Move();
		ThePlayers[1].Move();
	}

	TheBall.Move();	

	return true;
}

bool Pong::Draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

		SDL_Rect rect;

		rect.x = 0;
		rect.y = 0;
		rect.w = 800;
		rect.h = 600;
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		DrawCourt(renderer);

		ThePlayers[0].Render(renderer);
		ThePlayers[1].Render(renderer);

		TheBall.Render(renderer);

		char str[255];
		sprintf(str,"%d - %d",Score[0],Score[1]);

		debugPrinter->SetScale(8, 8);
		debugPrinter->SetJustification(DebugPrinter::Justifiy_Centre);
		debugPrinter->Print(renderer, 400,20,RGBTOCOLOR(255,255,255),str);
		debugPrinter->SetScale(1, 1);
		debugPrinter->SetJustification(DebugPrinter::Justifiy_Left);
		
	
	return true;
}

bool Pong::Shutdown()
{
	return true;
}



void Pong::DrawCourt(SDL_Renderer *renderer)
{	
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 100;
	rect.w = 800;
	rect.h = 10;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

	rect.x = 0;
	rect.y = 590;
	rect.w = 800;
	rect.h = 10;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

	rect.x = 395;
	rect.y = 100;
	rect.w = 10;
	rect.h = 600;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

}