#include "Player.h"
#include"SpriteManager.h"

Player* Player::instance = 0;
Player* Player::getInstance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}

void Player::onCollision(PhysicsBox* other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
}

void Player::update(float dt)
{
	MovableObject::update(dt);
}

Player::Player()
{
	setSprite(SPR(SPRITE_PLAYER));
	//this->setInterval(100);
	
}


Player::~Player()
{
}
