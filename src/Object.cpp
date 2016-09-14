#include <cmath>
#include <utility>
#include <iostream>

#include "Object.hpp"

#define DIRECTION_DEFAULT 0
#define DEPTH_DEFAULT     0
#define SPEED_DEFAULT     0


Object::Object(int32_t _x, int32_t _y) : x(_x), y(_y),
                                         xprevious(x), yprevious(y),
                                         direction(DIRECTION_DEFAULT),
                                         spr(NULL),
                                         depth(DEPTH_DEFAULT),
                                         vspeed(SPEED_DEFAULT), hspeed(SPEED_DEFAULT),
                                         speed(SPEED_DEFAULT), radius(0)
{
	
}

Object::~Object(void)
{
	this->x = 0;
	this->y = 0;
	this->xprevious = 0;
	this->yprevious = 0;
	this->vspeed = 0;
	this->hspeed = 0;
	this->speed = 0;
	this->depth = 0;
	this->direction = 0;
	
	// Warning, it will not deal with Sprite memory !
	this->spr = NULL;
}

void Object::moveOf(int32_t plusX, int32_t plusY)
{
	this->setX(this->x + plusX).setY(this->y + plusY);
}

void Object::applyHVSpeed(void)
{
	this->moveOf(this->hspeed, this->vspeed);
}


static double_t degreeToRadian(int32_t degree)
{
	return static_cast<double_t>(degree)*(M_PI/180.0);
}

/*static int32_t radianToDegree(double_t radian)
{
	return static_cast<int32_t>(radian*(180.0/M_PI));
}*/

uint32_t Object::distanceBetween(const Object &other) const
{
	uint32_t width    = std::abs(this->x - other.x);
	uint32_t height   = std::abs(this->y - other.y);
	return static_cast<uint32_t>(sqrt(std::pow(width, 2.0) + std::pow(height, 2.0)));
}

bool Object::collisionWith(const Object &other) const
{
	uint32_t maxDistance = this->radius + other.radius;
	uint32_t distance = this->distanceBetween(other);
	return distance <= maxDistance;
}


void Object::setHVSpeedWithDirectionAndSpeed(void)
{
	double_t radian = degreeToRadian(this->direction);
	this->hspeed = static_cast<int32_t>(this->speed*cos(radian));
	// *(-1), because we're talking about decreasing y.
	this->vspeed = static_cast<int32_t>(this->speed*sin(radian))*(-1);
}

void Object::duplicateMembersDuplicable(Object &other) const
{
	other.spr = this->spr;
	other.depth = this->depth;
	other.radius = this->radius;
	
}

void Object::update(void)
{
	this->beginStep();
	this->applyHVSpeed();
	this->step();
	this->endStep();
}

bool Object::outsideBoundaries(const Boundaries &bounds) const
{
	bool outsideLeft, outsideRight, outsideTop, outsideBottom;
	if (this->spr != NULL)
	{
		outsideLeft   = this->x + this->spr->w/2 < bounds.xmin;
		outsideRight  = this->x - this->spr->w/2 > bounds.xmax;
		outsideTop    = this->y + this->spr->h/2 < bounds.ymin;
		outsideBottom = this->y - this->spr->h/2 > bounds.ymax;
	}
	else
	{
		outsideLeft   = this->x < bounds.xmin;
		outsideRight  = this->x > bounds.xmax;
		outsideTop    = this->y < bounds.ymin;
		outsideBottom = this->y > bounds.ymax;
	}
	return outsideLeft || outsideRight || outsideTop || outsideBottom;
}

void Object::beginStep(void)
{
	
}

void Object::step(void)
{
	
}

void Object::endStep(void)
{
	
}

void Object::draw(void) const
{
	
}

Object& Object::setSprite(const Sprite *const sprite)
{
	this->spr = const_cast<Sprite*>(sprite);
	return *this;
}

Object& Object::setDepth(int32_t depth)
{
	this->depth = depth;
	return *this;
}

Object& Object::setX(int32_t x)
{
	this->xprevious = this->x;
	this->x = x;
	return *this;
}

Object& Object::setY(int32_t y)
{
	this->yprevious = this->y;
	this->y = y;
	return *this;
}

Object& Object::setDirection(int32_t direction)
{
	this->direction = direction;
	return *this;
}

int32_t Object::getX(void) const
{
	return this->x;
}

int32_t Object::getY(void) const
{
	return this->y;
}

int32_t Object::getXPrevious(void) const
{
	return this->xprevious;
}

int32_t Object::getYPrevious(void) const
{
	return this->yprevious;
}

int32_t Object::getDirection(void) const
{
	return this->direction;
}

const Sprite* Object::getSprite(void) const
{
	return this->spr;
}

int32_t Object::getDepth(void) const
{
	return this->depth;
}

Object& Object::setVSpeed(int32_t vspeed)
{
	this->vspeed = vspeed;
	return *this;
}

Object& Object::setHSpeed(int32_t hspeed)
{
	this->hspeed = hspeed;
	return *this;
}

int32_t Object::getVSpeed(void) const
{
	return this->vspeed;
}

int32_t Object::getHSpeed(void) const
{
	return this->hspeed;
}

Object& Object::setSpeed(int32_t speed)
{
	this->speed = speed;
	return *this;
}

int32_t Object::getSpeed(void) const
{
	return this->speed;
}

#define MAX_ANGLE 360
#define MIN_ANGLE 0
Object& Object::rotate(int32_t angle)
{
	this->direction = (this->direction + angle)%MAX_ANGLE;
	if (this->direction < MIN_ANGLE)
	{
		this->direction += MAX_ANGLE;
	}
	return *this;
}

Object& Object::rotateLeft(uint32_t angle)
{
	return rotate(static_cast<int32_t>(angle));
}

Object& Object::rotateRight(uint32_t angle)
{
	return rotate(static_cast<int32_t>(angle)*(-1));
}
