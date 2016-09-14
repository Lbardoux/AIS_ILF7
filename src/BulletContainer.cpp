#include <iterator>

#include "BulletContainer.hpp"

void BulletContainer::add(Bullet *bullet)
{
	this->bullets.push_back(bullet);
}


void BulletContainer::update(const Boundaries &bounds)
{
	auto iteratorBullet = this->bullets.begin();
	while(iteratorBullet != this->bullets.end())
	{
		Bullet *bullet = *iteratorBullet;
		bullet->update();
		if (bullet->outsideBoundaries(bounds))
		{
			if (bullet->destroyIfOutside())
			{
				auto nextIteratorBullet = std::next(iteratorBullet);
				this->bullets.erase(iteratorBullet);
				delete bullet;
				iteratorBullet = nextIteratorBullet;
				continue;
			}
		}
		if (bullet->mustBeDestroy())
		{
			auto nextIteratorBullet = std::next(iteratorBullet);
			this->bullets.erase(iteratorBullet);
			delete bullet;
			iteratorBullet = nextIteratorBullet;
			continue;
		}
		iteratorBullet++;
	}
}

void BulletContainer::draw(void)
{
	for (auto bullet : this->bullets)
	{
		bullet->draw();
	}
}

void BulletContainer::emptyContainer(void)
{
	while(!this->bullets.empty())
	{
		delete this->bullets.front();
		this->bullets.pop_front();
	}
}

BulletContainer::~BulletContainer(void)
{
	this->emptyContainer();
	
}
