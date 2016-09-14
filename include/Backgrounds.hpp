/**
 * @brief This file propose a container for every backgrounds possible
 * for the game.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BACKGROUNDS_HPP_INCLUDED
#define BACKGROUNDS_HPP_INCLUDED

#include "ImageLoader.hpp"

typedef SDL_Surface Background;


/**
 * @brief Maintenance instructions :
 * In order to get a fresh new Background, foolow these steps :
 *  - declare a public static Background *bac_nameOfBackground; on the class body
 *  - Then, create it on the .cpp like this : Background* Backgrounds::bac_nameOfBackground = NULL;
 *  - finally, deal with memory with load/unloadBackgrounds();
 */
class Backgrounds final
{
	public:
		static Background *bac_space;
		
		//! @brief Load every backgrounds into the static members.
		static void loadBackgrounds(void);
		
		//! @brief It will call SDL_FreeSurface statement for every Backgrounds.
		static void unloadBackgrounds(void);
		
		Backgrounds(void) = delete;
		Backgrounds(const Backgrounds &other) = delete;
		Backgrounds(Backgrounds &&other) = delete;
};

#endif
