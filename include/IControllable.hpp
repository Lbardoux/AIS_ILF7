/**
 * @brief It defines the common code for being able to control an Object
 * @author MLTCRBN
 * @version 1.0
 */
#ifndef ICONTROLLABLE_HPP_INCLUDED
#define ICONTROLLABLE_HPP_INCLUDED

#include <iostream>
#include <map>
#include <list>
#include <functional>
#include "Object.hpp"
#include "SDL_keysym.h"

typedef int32_t                           SDLK_int;
typedef std::function<void(Object&)>      InputFunction;
typedef std::map<SDLK_int, InputFunction> InputManager;
typedef std::list<SDLK_int>               InputList;


class BaseControllable
{
	public:
		virtual bool applyKeyEvent(SDLK_int key, Object &self) =0;
		virtual const InputList& getInputList(void) =0;
};

/**
 * @brief Ensure your got an inputManager accessible as static
 * And provide a safe way to add a function into it.
 * Also the querying way for the registered functions.
 */
template<typename Obj>
class IControllable : public BaseControllable
{
	protected:
		static InputManager inputManager;
		static InputList    inputList;
		
		/**
		 * @brief Use this function to bind an input to a function for this object
		 * You must use it at a derived class, not this one !
		 * @return true if the binding occurs, false if there is already a key binded here.
		 */
		static bool bindSDLKToFunction(SDLK_int key, InputFunction func)
		{
			if (Obj::inputManager.find(key) == Obj::inputManager.end())
			{
				Obj::inputManager.insert(std::pair<SDLK_int, InputFunction>(key, func));
				Obj::inputList.push_back(key);
				return true;
			}
			std::cerr << "[ERROR] : There is already a mapping for " << key << std::endl;
			return false;
		};
		
		
	public:
		/**
		 * @brief Execute the action binded with \a key.
		 * @param[in] key The SDLK_XXXX statement.
		 * @return true if there is an action binded, false otherwise.
		 */
		bool applyKeyEvent(SDLK_int key, Object &self) override
		{
			auto func = Obj::inputManager.find(key);
			if (func == Obj::inputManager.end())
			{
				return false;
			}
			func->second(self);
			return true;
		};
		
		const InputList& getInputList(void) override
		{
			return this->inputList;
		};
	
};

template<typename Obj>
InputManager IControllable<Obj>::inputManager;
template<typename Obj>
InputList IControllable<Obj>::inputList;

#endif
