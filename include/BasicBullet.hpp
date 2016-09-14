/**
 * @brief this is the most basic bullet usable.
 * It will go straight ahead the shooter.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BASICBULLET_HPP_INCLUDED
#define BASICBULLET_HPP_INCLUDED

#include <cstdint>
#include "Sprites.hpp"
#include "ILoadable.hpp"
#include "XmlLoader.hpp"
#include "NameResolver.hpp"
#include "Bullet.hpp"

//! @brief This bullet has no purpose, instead of going forward and getting
//! a normal strenght;
class BasicBullet : public Bullet,
                    ILoadable<BasicBullet>
{
	public:
		static uint32_t POWER;
		static int32_t  SPEED;
		static uint32_t RADIUS;
		static int32_t  DEPTH;
		
		
		BasicBullet(void) = delete;
		BasicBullet(int32_t x, int32_t y);
		~BasicBullet(void);
		
		static void loadFromXml(void);
		
		static void load(void);
		static void unload(void);
		
		void draw(void) const;

};

#endif
