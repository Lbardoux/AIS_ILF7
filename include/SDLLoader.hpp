/**
 * @brief Has in charge to load SDL stuffs.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef SDLLOADER_HPP_INCLUDED
#define SDLLOADER_HPP_INCLUDED

#include <cstdlib>
#include "SDL.h"

/**
 * @brief Will contains the main window pointer.
 */
class SDLLoader final
{
	public:
		/**
		* @brief Load the Basic SDL stuff, and create the first window, based on
		* \a width, \a height, \a fullscreen.
		* If any problem occurs, it will exit the main thread.
		*/
		static void loadSDL(uint32_t width, uint32_t height, bool fullscreen);
		
		/**
		 * @brief Release every possible things from SDL and sons.
		 */
		static void unloadSDL(void);
		 
};


#endif
