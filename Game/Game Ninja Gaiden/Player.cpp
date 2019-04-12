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
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		setVy(0);
		setIsOnGround(true);
	}
	preventMovementWhenCollision(collisionTime, nx, ny);
}

void Player::onUpdate(float dt)
{
	Player* player = Player::getInstance();
	float vx = GLOBALS_D("player_vx");
	float vroll = GLOBALS_D("player_roll");
	auto key = KEY::getInstance();

	switch (playerState)
	{
	case PLAYER_STATE_STAND:
		if (key->isLeftDown) {
			setDirection(DIRECTION_LEFT);
			player->setVx(-vx);
			setPlayerState(PLAYER_STATE_RUN);
		}
		else if (key->isRightDown)
		{
			setDirection(DIRECTION_RIGHT);
			player->setVx(vx);
			setPlayerState(PLAYER_STATE_RUN);
		}
		else if (key->isUpDown)
			setPlayerState(PLAYER_STATE_CLIMB);
		else if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_ATTACK);
		else if (key->isShurikenDown)
			setPlayerState(PLAYER_STATE_SHURIKEN);
		else if (key->isDownDown)
			setPlayerState(PLAYER_STATE_SIT);
		else if (key->isJumpDown) {
			setVy(vroll);
			setPlayerState(PLAYER_STATE_ROLL);
		}
		else
		{
			//không nhấn nút gì thì nó đứng yên.
			setVx(0);
			setAnimation(PLAYER_ACTION_STAND);
		}
			break;

	case PLAYER_STATE_RUN:
		setAnimation(PLAYER_ACTION_RUN);
		
		if (!key->isLeftDown && !key->isRightDown)
			setPlayerState(PLAYER_STATE_STAND);
		break;

	case PLAYER_STATE_CLIMB:
		setAnimation(PLAYER_ACTION_CLIMB);
		break;

	case PLAYER_STATE_ATTACK:	
		setAnimation(PLAYER_ACTION_ATTACK);
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;

	case PLAYER_STATE_SHURIKEN:
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;

	case PLAYER_STATE_SIT:
		setAnimation(PLAYER_ACTION_SIT);
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;

	case PLAYER_STATE_SITATTACK:
		setAnimation(PLAYER_ACTION_SITATTACK);
		break;

	case PLAYER_STATE_ROLL:
		
		setAnimation(PLAYER_ACTION_ROLL);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);
		break;

	case PLAYER_STATE_ROLLATTACK:
		setAnimation(PLAYER_ACTION_ROLLATTACK);
		break;
	}

	PhysicsObject::onUpdate(dt);
}


void Player::setPlayerState(PLAYER_STATE playerState)
{
	this->playerState = playerState;
}

Player::Player()
{
	setSprite(SPR(SPRITE_PLAYER));
	setDirection(DIRECTION_RIGHT);
	setPlayerState(PLAYER_STATE_STAND);
	setCollisionType(COLLISION_TYPE_PLAYER);
}


Player::~Player()
{
}
