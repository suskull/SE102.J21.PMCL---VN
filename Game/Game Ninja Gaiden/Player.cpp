#include "Player.h"


Player* Player::instance = 0;
Player* Player::getInstance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}

Player::Player()
{
}


Player::~Player()
{
}
