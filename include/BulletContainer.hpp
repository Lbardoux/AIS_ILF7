/**
 * @brief This file will provide a container for bullets, which have to
 * be use for every objects which desire to shoot :).
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BULLETCONTAINER_HPP_INCLUDED
#define BULLETCONTAINER_HPP_INCLUDED

#include <list>
#include "Bullet.hpp"


class BulletContainer final
{
	private:
		typedef std::list<Bullet*> ListBullet;
		
		ListBullet bullets; //! the container, but you won't have to use it directly
		
		void emptyContainer(void);
		
	public:
		~BulletContainer(void);
		
		
		void add(Bullet *bullet);
		
		//! @brief It will update every bullets on the container.
		void update(const Boundaries &bounds);
		
		void draw(void);
	
};

#endif
