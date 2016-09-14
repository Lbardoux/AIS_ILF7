#include <cstdlib>
#include <string>
#include <iostream>

#include "Backgrounds.hpp"



Background* Backgrounds::bac_space = NULL;


void Backgrounds::loadBackgrounds(void)
{
	std::cout << "[INFO] : Loading backgrounds." << std::endl;
	bac_space = loadImage(std::string("data/backgrounds/bac_space.png"), false);
	
	
	
	atexit(unloadBackgrounds);
	std::cout << "[INFO] : Backgrounds loaded succesfully." << std::endl;
}


void Backgrounds::unloadBackgrounds(void)
{
	unloadImage(&bac_space);
	std::cout << "[INFO] : Backgrounds completely removed." << std::endl;
}
