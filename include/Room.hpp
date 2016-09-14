/**
 * @brief A Room is basically a "level" for a game.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

#include <cstdint>
#include "Object.hpp"
#include "Backgrounds.hpp"
#include "GameState.hpp"
#include "Boundaries.hpp"

class Room : public GameState
{
	protected:
		Background *background;
		Boundaries dimension;
		
	
	public:
		uint32_t getWidth(void);
		uint32_t getHeight(void);
		const Boundaries& getBounds(void);
		
		Room& setBackground(Background *const bck);
		
		Room(void) = delete;
		Room(uint32_t width, uint32_t height);


};


#endif
