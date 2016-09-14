#include "Drawer.hpp"



void Drawer::drawSprite(SDL_Surface *const sprite, int32_t x, int32_t y, XYOnSprite pos)
{
	SDL_Surface *screen = SDL_GetVideoSurface();
	SDL_Rect rect;
	switch(pos)
	{
		case CENTERED:
			rect.x = x - sprite->w/2;
			rect.y = y - sprite->h/2;
			break;
		default:
			rect.x = x;
			rect.y = y;
	}
		
	SDL_BlitSurface(sprite, NULL, screen, &rect);
}
