/**
 * @brief This file has to manage every active states of the game, as a stack.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef STATESTACK_HPP_INCLUDED
#define STATESTACK_HPP_INCLUDED

#include <stack>
#include "GameState.hpp"


/**
 * @brief A specific stack to manage the game's states.
 * no state on the stack means the game is over.
 * for example :
 * @example ../../doc/examples/State_stack_example.cpp
 */
class StateStack final
{
	private:
		std::stack<GameState*> _states; //! A stack of Game_state, this class will not delete them at the end.
		
		
	public:
		//! @brief the default constructor.
		StateStack(void);
		
		//! @brief The destructor, clear the stack by calling every release() statement.
		~StateStack(void);
		
		/**
		 * @brief Push \a state on the stack (at the head).
		 * @details This function will also call the initialize() statement of the Game_state.
		 * @param[in,out] state The Game_state, which become the main state for the game (the one which shows up).
		 * @return true if the insertion goes well, false on the other cases.
		 */
		bool pushState(GameState *const state);
		
		/**
		 * @brief Pop the front state of the stack.
		 * @details This function will also call the release() statement of the Game_state.
		 * And \b delete the poping state..
		 * @return true if it was possible to "pop" a state, false on the other cases.
		 */
		bool popState(void);
		
		/**
		 * @brief Getting access to the first element of this stack.
		 * @return The first element if it exists, nullptr on the other case.
		 */
		GameState* top(void) const;
		
		/**
		 * @brief Check if the stack is empty.
		 * @return true if it is, false on the other case.
		 */
		bool empty(void) const;
		
		
		StateStack(const StateStack &other) = delete;
		StateStack(StateStack &&other) = delete;
		StateStack& operator=(const StateStack &other) = delete;
		StateStack& operator=(StateStack &&other) = delete;

};

#endif // STATE_STACK_HPP_INCLUDED
