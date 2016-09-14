/**
 * @brief This file will provide some drawing primitives.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef DRAWER_HPP_INCLUDED
#define DRAWER_HPP_INCLUDED

#include <cstdint>
#include "SDL.h"

typedef enum {CENTERED, TOPLEFT} XYOnSprite;


class Drawer final
{
	private:
		Drawer(void) = delete;
	
	public:
		/**
		 * @brief Draw \a sprite on the screen, at \a x and \a y.
		 * \a pos will be use to determine how to display the sprite :
		 * CENTERED means \a x and \a y are on the center of the image
		 * TOPLEFT  means ... on the top left corner of the sprite.
		 */
		static void drawSprite(SDL_Surface *const sprite, int32_t x, int32_t y, XYOnSprite pos);
};


#endif
