/**
 * @brief A "factory" to prevent troubles with inclusion.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef CANNONS_HPP_INCLUDED
#define CANNONS_HPP_INCLUDED

#include "BasicCannon.hpp"


typedef enum {
	BASIC_CANNON
	
} WeaponIdEnum;


//! @brief A factory for the weapons.
class Cannons final
{
	private:
		Cannons(void) = delete;
		
	public:
		/**
		 * @brief The return value will never be nullptr.
		 */
		static Cannon* createWeapon(BulletContainer *const container, WeaponIdEnum weapon);
	
};



#endif
