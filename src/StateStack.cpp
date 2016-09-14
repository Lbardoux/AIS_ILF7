#include "StateStack.hpp"

StateStack::StateStack(void)
{

}

StateStack::~StateStack(void)
{
	while(!this->empty())
	{
		this->popState();
	}
}

bool StateStack::pushState(GameState *const state)
{
	if (state == nullptr)
	{
		return false;
	}
	state->initialize();
	this->_states.push(state);
	return true;
}

bool StateStack::popState(void)
{
	if (!this->empty())
	{
		GameState *tmp = this->_states.top();
		this->_states.pop();
		tmp->release();
		delete tmp;
		return true;
	}
	return false;
}

GameState* StateStack::top(void) const
{
	return (!this->empty()) ? this->_states.top() : nullptr;
}

bool StateStack::empty(void) const
{
	return this->_states.empty();
}
