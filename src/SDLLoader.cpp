#include <iostream>
#include <cstdlib>

#include "SDLLoader.hpp"


#define ERROR_SDL                     -1
#define USER_SCREEN_INDEX             0
#define GETDESKTOPDISPLAYMODE_SUCCESS 0
#define SUBSYSTEMS                    SDL_INIT_VIDEO
#define VIDEO_INIT                    SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE
#define BIT_PER_PIXEL                 32
#define WINDOW_CAPTION                "Ambush In Sector ILF7"



void SDLLoader::loadSDL(uint32_t width, uint32_t height, bool fullscreen)
{
	if (SDL_Init(SUBSYSTEMS) == ERROR_SDL)
	{
		std::cerr << "[ERROR] : Unable to load SDL : " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
	
	uint32_t flags = VIDEO_INIT;
	if (fullscreen)
	{
		flags = flags | SDL_FULLSCREEN;
	}
	if (SDL_SetVideoMode(width, height, BIT_PER_PIXEL, flags) == NULL)
	{
		std::cerr << "[ERROR] : Cannot create the game window, " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
	atexit(SDLLoader::unloadSDL);
	std::cout << "[INFO] : SDL Loaded" << std::endl;
}

void SDLLoader::unloadSDL(void)
{
	SDL_Quit();
	std::cout << "[INFO] : SDL unloaded right now !" << std::endl;
	
}

