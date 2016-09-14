/**
 * @brief This is the most basic entity for a game.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <string>
#include <cstdint>
#include <cstdlib>

#include "Sprites.hpp"
#include "Boundaries.hpp"
#include "CreateArgument.hpp"



/**
 * @brief The default template for every object of the game.
 * You are not able to use a raw Object on your game.
 */
class Object
{
	protected:
		int32_t x;                 //! It x position on the Room.
		int32_t y;                 //! It y position on the Room.
		mutable int32_t xprevious; //! last x position.
		mutable int32_t yprevious; //! last y position.
		int32_t direction;         //! A direction for this object, an angle in mathematical way (0 -> 360, degree).
		Sprite *spr;               //! a read only address of it sprite.
		int32_t depth;             //! it depth for drawing, smaller means closer to the user (-5 is before 5 at drawing, so 5 is hiding by -5).
		int32_t vspeed;            //! number of pixel your object will move each frame verticaly.
		int32_t hspeed;            //! number of pixel your object will move each frame horizontaly.
		int32_t speed;             //! the speed of your object, in accordance with direction.
		uint32_t radius;           //! The radius of a circular bounding box
		
		
		/**
		 * @brief This function will duplicate only the member of this to \a other
		 * which are duplicable (not specific to the current instance).
		 * @param[inout] other The other object which will receive the duplciation.
		 */
		void duplicateMembersDuplicable(Object &other) const;
		
		//! @brief Functions to call every frame
		virtual void beginStep(void);
		virtual void step(void);
		virtual void endStep(void);

		//! @brief In pixels
		uint32_t distanceBetween(const Object &other) const;
	
	private:
			//! @brief Move using the (h&v)speed previously set.
			void applyHVSpeed(void);
			
			/**
			 * @brief Change the direction by applying \a angle to it.
			 * It will manage for bounds (0 to 360).
			 */
			Object& rotate(int32_t angle);
		
	public:
		Object(int32_t x, int32_t y);
		virtual ~Object(void);
		
		/**
		 * @brief What this object should do each frame
		 * It will call beginStep(), applyHVSpeed(), step(), and endStep()
		 */
		void update(void);
		
		// Main events of this object, callable.
		virtual void draw(void) const;
		// ...
		
		
		// setters
		Object& setSprite(const Sprite *const sprite);
		Object& setDepth(int32_t depth);
		Object& setX(int32_t x);
		Object& setY(int32_t y);
		Object& setDirection(int32_t direction);
		Object& setVSpeed(int32_t vspeed);
		Object& setHSpeed(int32_t hspeed);
		Object& setSpeed(int32_t speed);
		
		// getters
		int32_t            getX(void)         const;
		int32_t            getY(void)         const;
		int32_t            getXPrevious(void) const;
		int32_t            getYPrevious(void) const;
		int32_t            getDirection(void) const;
		const Sprite*      getSprite(void)    const;
		int32_t            getDepth(void)     const;
		int32_t            getVSpeed(void)    const;
		int32_t            getHSpeed(void)    const;
		int32_t            getSpeed(void)     const;
		
		
		/**
		 * @brief Apply a movement of \a plusX and \a plusY in relative mode.
		 * Than means from his actual position.
		 */
		void moveOf(int32_t plusX, int32_t plusY);
		
		/**
		 * @brief Compute the (h&v)speed with direction and speed
		 * If you want to use this, call it on beginStep(), otherwise
		 * it will be apply next frame.
		 */
		void setHVSpeedWithDirectionAndSpeed(void);
		
		//! @brief left means counter hour, right hour way
		Object& rotateLeft(uint32_t angle);
		Object& rotateRight(uint32_t angle);
		
		//! @brief uses radius and distance to decide if there is collision or not.
		bool collisionWith(const Object &other) const;
		
		bool outsideBoundaries(const Boundaries &bounds) const;
		
		
		Object(void) = delete;
		Object(const Object &other) = delete;
		Object(Object &&other) = delete;
		Object& operator=(const Object &other) = delete;
		Object& operator=(Object &&other) = delete;
		
};


#endif
