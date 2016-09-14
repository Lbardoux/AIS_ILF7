#include <iostream>

#include "BasicBullet.hpp"

namespace xml2 = tinyxml2;


uint32_t BasicBullet::POWER  = 1;
int32_t  BasicBullet::SPEED  = 25;
uint32_t BasicBullet::RADIUS = 8;
int32_t  BasicBullet::DEPTH  = 1;


BasicBullet::BasicBullet(int32_t x, int32_t y) : Bullet(x, y, BasicBullet::POWER)
{
	this->spr = Sprites::spr_playerBullet;
	this->speed  = BasicBullet::SPEED;
	this->depth  = BasicBullet::DEPTH;
	this->radius = BasicBullet::RADIUS;
}

BasicBullet::~BasicBullet(void)
{
	
}

#define VALUE "value"
void BasicBullet::loadFromXml(void)
{
	xml2::XMLDocument configXml;
	std::string nameOfFile;
	getFullNameOfFile("data/assets/basic_bullet.xml", nameOfFile);
	xml2::XMLNode *root = loadXmlFileAndDoChecks(nameOfFile, configXml);
	
	xml2::XMLElement *element = findThisElement(std::string("speed"), root);
	element->QueryIntAttribute(VALUE, &BasicBullet::SPEED);
	
	element = findThisElement(std::string("radius"), root);
	element->QueryUnsignedAttribute(VALUE, &BasicBullet::RADIUS);
	
	element = findThisElement(std::string("power"), root);
	element->QueryUnsignedAttribute(VALUE, &BasicBullet::POWER);
	
	element = findThisElement(std::string("depth"), root);
	element->QueryIntAttribute(VALUE, &BasicBullet::DEPTH);
}

void BasicBullet::load(void)
{
	BasicBullet::loadFromXml();
}

void BasicBullet::unload(void)
{
	
}

void BasicBullet::draw(void) const
{
	Drawer::drawSprite(this->spr, this->x, this->y, CENTERED);
}
