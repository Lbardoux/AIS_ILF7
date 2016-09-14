#include <cstdlib>
#include <string>
#include <iostream>

#include "Player.hpp"

namespace xml2 = tinyxml2;


Sprite*  Player::sprite = NULL;
uint32_t Player::cooldown;
uint32_t Player::invulnerabilityTime = 60;
uint32_t Player::weaponDuration;
int32_t  Player::baseSpeed = 6;
uint32_t Player::baseRadius = 20;
int32_t  Player::baseDepth = 0;


#define ROTATION_OF 10
#define VALUE_FIELD "value"


Player::Player(int32_t x, int32_t y, BulletContainer *const container) : Object(x, y),
                                                                         ILoadable(),
                                                                         IControllable(),
                                                                         IKillable(),
                                                                         IRotationable()
{
	this->weaponTimeLeft = 0;
	this->speed = Player::baseSpeed;
	this->actualCooldown = Player::cooldown;
	this->invulnerabilityTimeLeft = Player::invulnerabilityTime;
	this->health = Player::maxHealth;
	this->spr = Player::sprite;
	this->weapon = Cannons::createWeapon(container, BASIC_CANNON);
	
}

Player::~Player(void)
{
	if (this->weapon != nullptr)
	{
		delete this->weapon;
	}
	
}


#define decreaseIfLargerThanZero(what) if (what > 0) --what
void Player::step(void)
{
	decreaseIfLargerThanZero(this->invulnerabilityTimeLeft);
	decreaseIfLargerThanZero(this->actualCooldown);
	if (this->actualCooldown == 0)
	{
		this->weapon->shoot(this->x, this->y, this->direction);
		this->resetCooldown();
	}
	
}


void Player::draw(void) const
{
	if (this->invulnerabilityTimeLeft%2 == 0)
	{
		Sprite *actualSprite = this->getSpriteForThisAngle(this->direction);
		Drawer::drawSprite(actualSprite, this->x, this->y, CENTERED);
		if (this->health > 1)
		{
			Drawer::drawSprite(Sprites::spr_shield, this->x, this->y, CENTERED);
		}
	}
}

void Player::loadInputs(void)
{
	bindSDLKToFunction(Options::KEY_GO_UP, pressUp);
	bindSDLKToFunction(Options::KEY_GO_DOWN, pressDown);
	bindSDLKToFunction(Options::KEY_GO_RIGHT, pressRight);
	bindSDLKToFunction(Options::KEY_GO_LEFT, pressLeft);
	bindSDLKToFunction(Options::KEY_ROTATE_LEFT, pressRotateLeft);
	bindSDLKToFunction(Options::KEY_ROTATE_RIGHT, pressRotateRight);
}

void Player::loadConfiguration(void)
{
	xml2::XMLDocument configXml;
	std::string nameOfFile;
	getFullNameOfFile("data/assets/player.xml", nameOfFile);
	xml2::XMLNode *root = loadXmlFileAndDoChecks(nameOfFile, configXml);
	
	xml2::XMLElement *speed = findThisElement(std::string("speed"), root);
	speed->QueryIntAttribute(VALUE_FIELD, &Player::baseSpeed);
	
	xml2::XMLElement *cd = findThisElement(std::string("cooldown"), root);
	cd->QueryUnsignedAttribute(VALUE_FIELD, &Player::cooldown);
	
	xml2::XMLElement *invulnerability = findThisElement(std::string("invulnerabilityFrames"), root);
	invulnerability->QueryUnsignedAttribute(VALUE_FIELD, &Player::invulnerabilityTime);
	
	xml2::XMLElement *maxHp = findThisElement(std::string("maxHealth"), root);
	maxHp->QueryUnsignedAttribute(VALUE_FIELD, &Player::maxHealth);
	
	xml2::XMLElement *weapon = findThisElement(std::string("weaponDurationFrames"), root);
	weapon->QueryUnsignedAttribute(VALUE_FIELD, &Player::weaponDuration);
	
	xml2::XMLElement *depth = findThisElement(std::string("depth"), root);
	depth->QueryIntAttribute(VALUE_FIELD, &Player::baseDepth);
	
	xml2::XMLElement *radius = findThisElement(std::string("boundingCircleRadius"), root);
	radius->QueryUnsignedAttribute(VALUE_FIELD, &Player::baseRadius);
	
}

void Player::load(void)
{
	sprite = Sprites::spr_player;
	loadInputs();
	loadConfiguration();
	Player::initSpriteBuffer();
}

void Player::unload(void)
{
	inputManager.clear();
	Player::emptySpriteBuffer();
	Player::sprite = NULL;
}

void Player::pressUp(Object &self)
{
	self.moveOf(0, -self.getSpeed());
}

void Player::pressDown(Object &self)
{
	self.moveOf(0, self.getSpeed());
}

void Player::pressRight(Object &self)
{
	self.moveOf(self.getSpeed(), 0);
}

void Player::pressLeft(Object &self)
{
	self.moveOf(-self.getSpeed(), 0);
}

void Player::pressRotateLeft(Object &self)
{
	self.rotateLeft(ROTATION_OF);
}

void Player::pressRotateRight(Object &self)
{
	self.rotateRight(ROTATION_OF);
}

bool Player::isInvulnerable(void)
{
	return this->invulnerabilityTimeLeft > 0;
}

uint32_t Player::getWeaponDuration(void)
{
	return Player::weaponDuration;
}

uint32_t Player::getWeaponTimeLeft(void)
{
	return this->weaponTimeLeft;
}

void Player::resetCooldown(void)
{
	this->actualCooldown = Player::cooldown;
}

