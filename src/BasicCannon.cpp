#include "BasicCannon.hpp"

BasicCannon::BasicCannon(BulletContainer *container) : Cannon(container)
{
	
}

BasicCannon::~BasicCannon(void)
{
	
}

void BasicCannon::shoot(int32_t x, int32_t y, int32_t angle)
{
	Bullet *shot = new BasicBullet(x, y);
	this->bullets->add(shot);
	shot->setDirection(angle).setHVSpeedWithDirectionAndSpeed();
}
