#include "Object.h"
#include <SDL.h>

bool Object::IsColliding(const Object& o)
{
	if((posX + w) < o.posX) return false;
	if((posX ) > (o.posX + o.w)) return false;

	if((posY + h) < o.posY) return false;
	if((posY ) > (o.posY + o.h)) return false;

	return true;
}

void Object::Render(SDL_Renderer* renderer)
{	
	SDL_Rect rect;

	rect.x = (int)posX;
	rect.y = (int)posY;
	rect.w = (int)w;
	rect.h = (int)h;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

}
