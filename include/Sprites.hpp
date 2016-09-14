/**
 * @brief Store every game's sprite.
 * There is a semantic distinction right here, but it's just for users.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef SPRITES_HPP_INCLUDED
#define SPRITES_HPP_INCLUDED

#include "ImageLoader.hpp"
#include "Drawer.hpp"

typedef SDL_Surface Sprite;

/**
 * @brief Maintenance instructions
 * For each new sprite, you'll have to :
 *  - declare a public static Sprite *spr_nameOfSprite;
 *  - Initialize it at the .cpp (Sprite* Sprites::nameOfSprite = NULL;)
 *  - Then deal with allocation and desallocation on load/unloadSprites();
 */
class Sprites final
{
	public:
		static Sprite *spr_player;
		static Sprite *spr_shield;
		static Sprite *spr_playerBullet;
		
		
		//! @brief Load every sprites you need.
		static void loadSprites(void);
		
		//! @brief Unload every possible sprites.
		static void unloadSprites(void);
		
		
		Sprites(void) = delete;
		Sprites(const Sprites &other) = delete;
		Sprites(Sprites &&other) = delete;
	
};

#endif
