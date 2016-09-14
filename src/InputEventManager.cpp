#include <cstdlib>

#include "InputEventManager.hpp"


InputEventManager::InputEventManager(void)
{
	this->keys = SDL_GetKeyState(NULL);
}

InputEventManager::~InputEventManager(void)
{
	this->keys = NULL;
	this->registry.clear();
}

void InputEventManager::registerInputs(const InputList &inputList, BaseControllable *const obj)
{
	for(auto it : inputList)
	{
		this->registry.push_back(std::make_pair(it, obj));
	}
}

bool InputEventManager::addControllable(Object *const object)
{
	if (BaseControllable *tmp = dynamic_cast<BaseControllable*>(object))
	{
		this->registerInputs(tmp->getInputList(), tmp);
		return true;
	}
	return false;
}

void InputEventManager::checkAndApplyKeys(void)
{
	for(auto pair : this->registry)
	{
		if (this->keys[pair.first])
		{
			// dynamic_cast is allow because we only inserted Object at the very beginning
			pair.second->applyKeyEvent(pair.first, *(dynamic_cast<Object*>(pair.second)));
		}
	}
}
