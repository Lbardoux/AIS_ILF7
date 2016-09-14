/**
 * @brief The entity the player is able to control.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <cstdint>
#include <string>

#include "Object.hpp"
#include "Sprites.hpp"
#include "XmlLoader.hpp"
#include "NameResolver.hpp"
#include "Options.hpp"

// components
#include "ILoadable.hpp"
#include "IControllable.hpp"
#include "IKillable.hpp"
#include "IRotationable.hpp"

#include "Cannons.hpp"
#include "CreateArgument.hpp"


//! @brief The specific object than the player controls.
class Player final : public Object,
                     protected ILoadable<Player>,
                     public IControllable<Player>,
                     public IKillable<Player>,
                     public IRotationable<Player, 10>
{
	protected:
		// Required for IRotationable
		static Sprite *sprite;
		friend class IRotationable<Player, 10>;
		
		
	
	private:
		//static std::string name;
		
		static uint32_t cooldown;
		static uint32_t invulnerabilityTime;
		static uint32_t weaponDuration;
		static int32_t  baseSpeed;
		static uint32_t baseRadius;
		static int32_t  baseDepth;
		
		// about timing
		uint32_t actualCooldown;          //! when it reaches 0, you could shoot.
		uint32_t invulnerabilityTimeLeft; //! when it reaches 0, you're able to be kill.
		uint32_t weaponTimeLeft;          //! Time before you get back your old weapon
		
		Cannon *weapon;                   //! The current weapon, it never has to be nullptr
		
		
		
		//! @brief Inputs have to be declared here.
		static void loadInputs(void);
		
		//! @brief Everything which have to be load from an xml file.
		static void loadConfiguration(/*Player &obj*/);
		
		void step(void) override;
		
		
	public:
		Player(void) = delete;
		Player(int32_t x, int32_t y, BulletContainer *const container);
		~Player(void);
		
		void draw(void) const override;
		
		
		// This is how to instanciate a Player over the game
		//Player* create(int32_t x, int32_t y, CreateArgument *args) const override;
		
		
		//! Inputs reactions functions
		static void pressUp(Object &self);
		static void pressDown(Object &self);
		static void pressRight(Object &self);
		static void pressLeft(Object &self);
		static void pressRotateLeft(Object &self);
		static void pressRotateRight(Object &self);
		
		bool     isInvulnerable(void);
		uint32_t getWeaponDuration(void);
		uint32_t getWeaponTimeLeft(void);
		
		void resetCooldown(void);
		
		
		// Required from ILoadable 
		static void load(void);
		static void unload(void);
		
	
};


class PlayerArgument : public CreateArgument
{
	public:
		BulletContainer *container;
		PlayerArgument(void) = delete;
		PlayerArgument(BulletContainer *container) : CreateArgument()
		{
			this->container = container;
		}
};


#endif
