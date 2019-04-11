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

void Player::onUpdate(float dt)
{
	Player* player = Player::getInstance();
	float vx = GLOBALS_D("player_vx");

	if (KEY::getInstance()->isLeftDown)
	{
		setDirection(DIRECTION_LEFT);
		setAnimation(PLAYER_STATE_RUN);
		player->setVx(-vx);
	}
	else if (KEY::getInstance()->isRightDown)
	{
		setDirection(DIRECTION_RIGHT);
		setAnimation(PLAYER_STATE_RUN);
		player->setVx(vx);
	}
	else if (KEY::getInstance()->isUpDown)
	{
		setAnimation(PLAYER_STATE_CLIMB);
		player->setVy(vx);
	}
	else if (KEY::getInstance()->isDownDown)
	{
		setAnimation(PLAYER_STATE_CLIMB);
		player->setVy(-vx);
	}
	else if (KEY::getInstance()->isAttackDown)
	{
		setAnimation(PLAYER_STATE_ATTACK);
	}
	else if (KEY::getInstance()->isJumpDown)
	{
		setVy(100);
		setAnimation(PLAYER_STATE_ROLL);
	}
	else
	{
		setAnimation(PLAYER_STATE_STAND);
		player->setVx(0);
	}
	PhysicsObject::onUpdate(dt);
}


Player::Player()
{
	setSprite(SPR(SPRITE_PLAYER));
	setDirection(DIRECTION_RIGHT);
}


Player::~Player()
{
}
