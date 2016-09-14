/**
 * @brief This file offers a class to manage input events during game execution
 * @author MTLCRBN
 * @version
 */
#ifndef INPUTEVENTMANAGER_HPP_INCLUDED
#define INPUTEVENTMANAGER_HPP_INCLUDED

#include <list>
#include <set>
#include <cstdint>
#include <utility>

#include "IControllable.hpp"
#include "Object.hpp"
#include "SDL.h"

#define PAIR_CONTENT SDLK_int, BaseControllable*
typedef std::list<std::pair<PAIR_CONTENT>> InputRegistry;


class InputEventManager final
{
	private:
		InputRegistry registry;
		uint8_t *keys;
		
		void registerInputs(const InputList &inputList, BaseControllable *const obj);
		
	public:
		InputEventManager(void);
		~InputEventManager(void);
		
		//! @brief \a object will be manage by this InputEventManager.
		bool addControllable(Object *const object);
		
		//! @brief Check for keys pressed and apply events.
		void checkAndApplyKeys(void);
		
		
		InputEventManager(const InputEventManager &other) = delete;
		InputEventManager(InputEventManager &&other) = delete;
		InputEventManager& operator=(const InputEventManager &other) = delete;
		InputEventManager& operator=(InputEventManager &&other) = delete;
		
};


#endif
