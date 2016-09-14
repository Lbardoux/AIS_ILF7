#include <iostream>
#include <cstdlib>

#include "SDLLoader.hpp"
#include "GameInitializer.hpp"
#include "Backgrounds.hpp"
#include "InputEventManager.hpp"

int main(int argc, char **argv)
{
	GameInitializer::initGame(argc, argv);
	bool process = true;
	SDL_Event event;
	
	BulletContainer list;
	Boundaries bounds = {0, 0, 640, 480};
	Player *myPlayer = new Player(320, 240, &list);
	
	InputEventManager manager;
	manager.addControllable(myPlayer);
	
	SDL_Surface *screen = SDL_GetVideoSurface();
	while(process)
	{
		manager.checkAndApplyKeys();
		myPlayer->update();
		list.update(bounds);
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						process = false;
					break;
				default:
					break;
			}
		}
		SDL_BlitSurface(Backgrounds::bac_space, NULL, screen, NULL);
		list.draw();
		myPlayer->draw();
		SDL_Flip(screen);
		SDL_Delay(GameInitializer::FRAME_RATE);
	}
	delete myPlayer;
	return EXIT_SUCCESS;
}
