/**
 * @brief Everything to initialize the game
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef GAMEINITIALIZER_HPP_INCLUDED
#define GAMEINITIALIZER_HPP_INCLUDED

#include <cstdint>
#include "XmlLoader.hpp"
#include "SDLLoader.hpp"
#include "NameResolver.hpp"
#include "Backgrounds.hpp"
#include "Sprites.hpp"
#include "Objects.hpp"
#include "Options.hpp"


/**
 * @brief This class has to load the initial configuration for the game.
 * If there is something else to initialize, it has to be write on the
 * initGame() function.
 * It also contains every information for further usage.
 */
class GameInitializer final
{
	public:
		static uint32_t    FRAME_RATE;    //! How many ms we should delay between each loop.
		static bool        FULLSCREEN;    //! If the game is/was on fullscreen or not.
		static uint32_t    SCREEN_HEIGHT; //! If it was/is not on fullscreen, what the screen's height.
		static uint32_t    SCREEN_WIDTH;  //! If it was/is not on fullscreen, what the screen's width.
		static uint32_t    FPS_READ;      //! The number read before computation.
		static std::string fullName;   //! The configuration xml file name with absolute path
		static bool        MODIFIED;          //! If the configuration was modify.
		
		/**
		 * @brief Read the configuration to init the game.
		 * You just have to call this function before using anything else.
		 */
		static void initGame(int argc, char **argv);
		
		GameInitializer(void) = delete;
		GameInitializer(const GameInitializer &other) = delete;
		GameInitializer(GameInitializer &&other) = delete;
		
};



#endif
