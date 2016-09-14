/**
 * @brief This define an interface for every Game_engine which need to be used with the others files.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef IGAMEENGINE_HPP_INCLUDED
#define IGAMEENGINE_HPP_INCLUDED

/**
 * @brief An interface for every game engine, in order to use them on every components
 * of the main game architecture.
 */
class IGameEngine
{
    public:
        //! @brief the virtual destructor for every derivated classes.
        virtual ~IGameEngine(void) =0;


};

#endif // IGAMEENGINE_HPP_INCLUDED
