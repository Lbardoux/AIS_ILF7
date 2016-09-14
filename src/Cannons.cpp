#include "Cannons.hpp"

Cannon* Cannons::createWeapon(BulletContainer *const container, WeaponIdEnum weapon)
{
	Cannon *cannon = nullptr;
	switch(weapon)
	{
		case BASIC_CANNON:
			cannon = new BasicCannon(container);
			break;
		default:
			cannon = new BasicCannon(container);
	}
	return cannon;
}
