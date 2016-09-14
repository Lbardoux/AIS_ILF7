#include <cstdlib>
#include "Room.hpp"

uint32_t Room::getWidth(void)
{
	return this->dimension.xmax;
}

uint32_t Room::getHeight(void)
{
	return this->dimension.ymax;
}

const Boundaries& Room::getBounds(void)
{
	return this->dimension;
}

Room& Room::setBackground(Background *const bck)
{
	this->background = bck;
	return *this;
}

Room::Room(uint32_t width, uint32_t height)
{
	this->dimension.ymax = height;
	this->dimension.xmax = width;
	this->dimension.ymin = 0;
	this->dimension.xmin = 0;
	this->background = NULL;
}

