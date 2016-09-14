/**
 * @brief A handler for the game options.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef OPTIONS_HPP_INCLUDED
#define OPTIONS_HPP_INCLUDED

#include <string>
#include <cstdint>
#include "XmlLoader.hpp"
#include "NameResolver.hpp"

typedef enum{EASY, NORMAL, INSANE} Difficulty;

//! @brief a Convenience to hanlde every options through the game.
class Options final
{
	private:
		static bool MODIFIED;
		static std::string filename;
		
		//! @brief Will write the new options if modified !
		static void dumpOptions(void);
	
	public:
		static bool       DEFAULT_INPUTS; //! Think to change it if there is modifications
		static uint32_t   KEY_GO_UP;
		static uint32_t   KEY_GO_DOWN;
		static uint32_t   KEY_GO_RIGHT;
		static uint32_t   KEY_GO_LEFT;
		static uint32_t   KEY_ROTATE_LEFT;
		static uint32_t   KEY_ROTATE_RIGHT;
		static uint32_t   KEY_PAUSE;
		static bool       MUSIC_ENABLED;
		static bool       SOUND_ENABLED;
		static Difficulty DIFFICULTY;
		
		//! @brief Must call that in order to initialize values
		static void initAndReadOptions(void);
		
		
		Options(void) = delete;
	
};


#endif
