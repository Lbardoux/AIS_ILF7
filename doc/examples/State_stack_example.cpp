#include "State_stack.hpp"

int main(void)
{
    State_stack myStack;
    MyGame_state *state = new MyGame_state();

    // it is possible to check for the return value here.
    myStack.push(state);

    MyGame_state *usage = myStack.top();

    // check for nullity is important
    if (usage != nullptr)
    {
        // do some stuff...
    }

    // it is possible to check for the return value here.
    myStack.pop();
    return 0;
}
