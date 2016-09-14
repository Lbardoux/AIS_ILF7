#include <cstdlib>
#include <iostream>

#include "Objects.hpp"


void Objects::loadObjects(void)
{
	std::cout << "[INFO] : Initializing objects." << std::endl;
	Player::load();
	BasicBullet::load();
	
	atexit(unloadObjects);
	std::cout << "[INFO] : Objects loaded succesfully." << std::endl;
}


void Objects::unloadObjects(void)
{
	Player::unload();
	BasicBullet::unload();
	std::cout << "[INFO] : Objects     completely removed." << std::endl;
}
