#include "Player.h"
#include"SpriteManager.h"

Player* Player::instance = 0;
Player* Player::getInstance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}

Player::Player()
{
	setSprite(SPR(SPRITE_PLAYER));
	//this->setInterval(100);
}


Player::~Player()
{
}
