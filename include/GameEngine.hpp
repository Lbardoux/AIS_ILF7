#ifndef GAMEENGINE_HPP_INCLUDED
#define GAMEENGINE_HPP_INCLUDED

#include "IGameEngine.hpp"
#include "StateStack.hpp"


class GameEngine final : public IGameEngine
{
    private:
        StateStack _states; //! Every game's states, for the run part.


};


#endif
