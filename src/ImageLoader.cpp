#include <iostream>
#include <cstdlib>
#include <cassert>

#include "ImageLoader.hpp"



SDL_Surface* loadImage(const std::string &nameFromRoot, bool alpha)
{
	std::string fullName;
	getFullNameOfFile(nameFromRoot, fullName);
	SDL_Surface *preload = IMG_Load(fullName.c_str());
	if (preload == NULL)
	{
		std::cerr << "[ERROR] : Unable to load " << nameFromRoot << std::endl;
		exit(EXIT_FAILURE);
	}
	
	SDL_Surface *result = NULL;
	if (alpha)
	{
		result = SDL_DisplayFormatAlpha(preload);
	}
	else
	{
		result = SDL_DisplayFormat(preload);
	}
	if (result == NULL)
	{
		std::cerr << "[ERROR] : Unable to convert " << nameFromRoot << " to the right format." << std::endl;
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(preload);
	std::cout << "[INFO] : " << nameFromRoot << " loaded." << std::endl;
	return result;
}

void unloadImage(SDL_Surface **image)
{
	if (*image != NULL)
	{
		SDL_FreeSurface(*image);
		*image = NULL;
	}
}

SDL_Surface* rotateThisImageOf(SDL_Surface *const img, double_t angle)
{
	assert(img != NULL);
	SDL_Surface *tmp = rotozoomSurface(img, angle, 1.0, 1);
	if (tmp == NULL)
	{
		std::cerr << "[ERROR] : Unable to rotate an image, abort !" << std::endl;
		exit(EXIT_FAILURE);
	}
	return tmp;
}
