/**
 * @brief This file describe a basic virtual class to define a "state" for any game.
 * A state may be a main menu, a level, etc.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef GAMESTATE_HPP_INCLUDED
#define GAMESTATE_HPP_INCLUDED

#include "IGameEngine.hpp"


//! @brief A virtual class here for the game state pattern.
class GameState
{
	public:
		//! @brief This function must initialize every components of the current state.
		virtual void initialize(void) =0;
		
		//! @brief This function must draw every components of the current state.
		virtual void draw(void) =0;
		
		//! @brief This function must update every components of the current state.
		virtual void update(void) =0;
		
		//! @brief This function must release every allocated components.
		virtual void release(void) =0;
		
		//! @brief the virtual destructor, for derived classes.
		virtual ~GameState(void) {};
		
	protected:
		IGameEngine *game; //! The game engine you wish to use.
	
};

#endif
