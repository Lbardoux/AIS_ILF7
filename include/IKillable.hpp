/**
 * @brief Factorize common code to every killable enemy
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef IKILLABLE_HPP_INCLUDED
#define IKILLABLE_HPP_INCLUDED

#include <cstdint>

/**
 * @brief A Killable is an Object which is allow to die :D
 * This class will manage the health and provide utilitray functions.
 *
 * In order to use that class, you must define maxHealth value
 */
template<typename Obj>
class IKillable
{
	protected:
		uint32_t health;
		static uint32_t maxHealth;
		
	public:
		bool isDead(void)
		{
			return this->health == 0;
		};
		
		uint32_t getHealth(void)
		{
			return this->health;
		};
		
		void heal(uint32_t value)
		{
			this->health = std::min(Obj::maxHealth, this->health + value);
		};
		
		void hurt(uint32_t value)
		{
			this->health = std::max(0, this->health - value);
		};
	
};

template<typename Obj>
uint32_t IKillable<Obj>::maxHealth;

#endif
