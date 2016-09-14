/**
 * @brief This will decide how to shoot on the game.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef CANNON_HPP_INCLUDED
#define CANNON_HPP_INCLUDED

#include <list>
#include <cstdint>
#include "BulletContainer.hpp"


/**
 * @brief The daughters of this class will decide how to shoot (basic shot,
 * multi directionnal, etc).
 * By using the shoot() method.
 */
class Cannon
{
	protected:
		BulletContainer *bullets; //! a non proprietory pointer to the list.
		
		Cannon(void) = delete;
		Cannon(BulletContainer *container)
		{
			this->bullets = container;
		};
		
	public:
		virtual void shoot(int32_t x, int32_t y, int32_t angle) =0;
		virtual ~Cannon(void)
		{
			this->bullets = nullptr; // We won't manage memory here
		};
	
};

#endif
