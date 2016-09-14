/**
 * @brief The basics for a Bullet on the game.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BULLET_HPP_INCLUDED
#define BULLET_HPP_INCLUDED

#include <list>
#include <cstdint>
#include "Object.hpp"



/**
 * @brief This is the basics of bullet.
 * In order to use it, you must first inherit of this class :
 * class MyBullet : public Bullet {...};
 * 
 * By default, a Bullet will be destroy when it comes out of bound
 * But you're able to change that with the legacy, you just have to
 * override the destroyIfOutside() function, by changing the return value.
 * By doing this, you'll have to override mustBeDestroy() function
 * For example, you could imagine a bullet that move wrap over the screen,
 * but disapear after a while.
 */
class Bullet : public Object
{
	protected:
		uint32_t power; //! how much damage this bullet could inflict.
		
		Bullet(void) = delete;
		Bullet(int32_t x, int32_t y, uint32_t strenght) : Object(x, y), power(strenght) {};
		
	public:
		virtual bool destroyIfOutside(void)
		{
			return true;
		};
		
		virtual bool mustBeDestroy(void)
		{
			return false;
		};
		
		virtual ~Bullet(void){};
	
};


#endif
