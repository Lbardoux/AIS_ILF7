#include "BattleRoom.hpp"

BattleRoom::BattleRoom(uint32_t width, uint32_t height) : Room(width, height)
{
	
}

BattleRoom::~BattleRoom(void)
{
	
}

void BattleRoom::initialize(void)
{
	this->playerBullets = new BulletContainer();
	this->enemyBullets = new BulletContainer();
	
	this->player = new Player(this->getWidth()/2, this->getHeight()/2, this->playerBullets);
}

void BattleRoom::draw(void)
{
	// update here with a specific class
	this->player->draw();
	this->playerBullets->draw();
	this->enemyBullets->draw();
}

void BattleRoom::update(void)
{
	this->player->update();
	this->playerBullets->update();
	this->enemyBullets->update();
	
}

void BattleRoom::release(void)
{
	delete this->playerBullets;
	delete this->enemyBullets;
	delete this->player;
}

