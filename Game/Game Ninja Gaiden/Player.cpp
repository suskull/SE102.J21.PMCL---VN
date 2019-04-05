#include "Player.h"
#include"SpriteManager.h"

Player* Player::instance = 0;
Player* Player::getInstance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}

void Player::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
}



Player::Player()
{
	setSprite(SPR(SPRITE_PLAYER));
}


Player::~Player()
{
}
