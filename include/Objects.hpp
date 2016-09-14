/**
 * @brief The most important registry of the game, it will contain
 * every Objects for the game.
 * Those objects are pattern in order to create new fresh copy.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef OBJECTS_HPP_INCLUDED
#define OBJECTS_HPP_INCLUDED


#include "Player.hpp"
#include "BasicBullet.hpp"

/**
 * @brief A container for every objects of the game.
 * every objects must be declared here before using
 */
class Objects final
{
	public:
		//! @brief Initialize objects.
		static void loadObjects(void);
		
		//! @brief Desinitialize objects.
		static void unloadObjects(void);
		
		
		Objects(void) = delete;
		Objects(const Objects &other) = delete;
		Objects(Objects &&other) = delete;
	
};



#endif
