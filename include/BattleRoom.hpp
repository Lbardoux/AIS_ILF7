/**
 * @brief This room will create every common components for a battle room
 * As instead, with the player ship and enemies to shoot at.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BATTLEROOM_HPP_INCLUDED
#define BATTLEROOM_HPP_INCLUDED

#include <cstdint>
#include "Room.hpp"
#include "Player.hpp"
#include "BulletContainer.hpp"

class BattleRoom : public Room
{
	public:
		BattleRoom(void) = delete;
		BattleRoom(uint32_t width, uint32_t height);
		virtual ~BattleRoom(void);
		
		virtual void initialize(void) override;
		virtual void draw(void)       override;
		virtual void update(void)     override;
		virtual void release(void)    override;
		
	protected:
		BulletContainer *playerBullets;
		BulletContainer *enemyBullets;
		Player          *player;

};

#endif
