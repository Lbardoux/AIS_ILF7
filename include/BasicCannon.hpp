/**
 * @brief The main canon, it just shoot forward.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BASICCANNON_HPP_INCLUDED
#define BASICCANNON_HPP_INCLUDED

#include "Cannon.hpp"
#include "BasicBullet.hpp"


class BasicCannon final : public Cannon
{
	public:
		BasicCannon(void) = delete;
		BasicCannon(BulletContainer *container);
		~BasicCannon(void);
		
		void shoot(int32_t x, int32_t y, int32_t angle) override;
	
};


#endif
