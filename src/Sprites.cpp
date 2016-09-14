#include <iostream>
#include <string>

#include "Sprites.hpp"


Sprite* Sprites::spr_player       = NULL;
Sprite* Sprites::spr_shield       = NULL;
Sprite* Sprites::spr_playerBullet = NULL;


void Sprites::loadSprites(void)
{
	std::cout << "[INFO] : Loading sprites." << std::endl;
	spr_player = loadImage(std::string("data/sprites/spr_player.png"), true);
	spr_shield = loadImage(std::string("data/sprites/spr_shield.png"), true);
	spr_playerBullet = loadImage(std::string("data/sprites/spr_playerBullet.png"), true);
	
	atexit(unloadSprites);
	std::cout << "[INFO] : Sprites loaded succesfully." << std::endl;
}


void Sprites::unloadSprites(void)
{
	unloadImage(&spr_player);
	unloadImage(&spr_shield);
	unloadImage(&spr_playerBullet);
	
	std::cout << "[INFO] : Sprites     completely removed." << std::endl;
}
