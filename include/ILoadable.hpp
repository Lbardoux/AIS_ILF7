/**
 * @brief It defines the behavior for an Object to be loaded by the Object registry
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef ILOADABLE_HPP_INCLUDED
#define ILOADABLE_HPP_INCLUDED

#ifdef __GNUC__
    #define UNUSED(x) x __attribute__ ((unused))
#else
    #define UNUSED(x) x
#endif

/**
 * @brief An interface to do so.
 * In order to being able to load an Object, you'll have to inherit
 * this Interface, which will do some verifications.
 * class MyObject : public Object, protected ILoadable<MyObject>
 *
 * And then define the :
 * static void load(void)
 * and
 * static void unload(void)
 */
template<typename Obj>
class ILoadable
{
	protected:
		ILoadable(void)
		{
			/*Obj* UNUSED((*f_load)(void)) = &Obj::load;
			void UNUSED((*f_unload)(Obj*)) = &Obj::unload;*/
			void UNUSED((*f_load)(void)) = &Obj::load;
			void UNUSED((*f_unload)(void)) = &Obj::unload;
		};
};


#endif
