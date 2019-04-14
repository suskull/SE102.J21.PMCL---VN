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

void Player::update(float dt)
{
	Player* player = Player::getInstance();
	float vx = GLOBALS_D("player_vx");
	float vroll = GLOBALS_D("player_roll");
	auto key = KEY::getInstance();

	switch (playerState)
	{
	//xong
	case PLAYER_STATE_STAND:
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		isAttacked = false;
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
		{
			
			
			setPlayerState(PLAYER_STATE_SHURIKEN);
		}
			
		else if (key->isDownDown)
			setPlayerState(PLAYER_STATE_SIT);
		else if (key->isJumpDown && getIsOnGround()) {
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

	//xong
	case PLAYER_STATE_RUN:
	{
		setAnimation(PLAYER_ACTION_RUN);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		if (!key->isLeftDown && !key->isRightDown)
			setPlayerState(PLAYER_STATE_STAND);
		else if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_ATTACK);
		else if (key->isJumpDown)
		{
			setVy(vroll);
			setPlayerState(PLAYER_STATE_ROLL);
		}
		break;
	}

	case PLAYER_STATE_CLIMB:
		setAnimation(PLAYER_ACTION_CLIMB);
		break;
	//gần xong
	case PLAYER_STATE_ATTACK: {
		setVx(0);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());

		Sword* sword = Sword::getInstance();
		if (!isAttacked)
		{
			sword->setAlive(true);
			setAnimation(PLAYER_ACTION_ATTACK);
			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
		{
			sword->setAlive(false);
			setPlayerState(PLAYER_STATE_STAND);
		}
		break;
	}
	//xong	
	case PLAYER_STATE_SHURIKEN: {
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			/*Shuriken* shuriken = new Shuriken();
			shuriken->setX(this->getX() + 12 * getDirection());
			this->setVx(0);
			shuriken->setY(this->getY() - 5);
			shuriken->setVx(150 * getDirection());*/

			WindmillShuriken * ws = new WindmillShuriken();
			ws->setX(this->getX() + getWidthCurrentFrame()* getDirection());
			this->setVx(0);
			ws->setY(this->getY() - 5);
			ws->setVx(150 * getDirection());
			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}

	//xong
	case PLAYER_STATE_SIT:
		isAttacked = false;
		setDx(0);
		setVx(0);
		setAnimation(PLAYER_ACTION_SIT);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		if (!key->isDownDown)
			setPlayerState(PLAYER_STATE_STAND);
		if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_SITATTACK);
		break;
	//xong
	case PLAYER_STATE_SITATTACK:
	{
		Sword* sword = Sword::getInstance();
		if (!isAttacked)
		{
			sword->setAlive(true);
			setAnimation(PLAYER_ACTION_SITATTACK);
			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
		{
			sword->setAlive(false);
			setPlayerState(PLAYER_STATE_SIT);
		}
		break;
	}

	//xong
	case PLAYER_STATE_ROLL:
	{
		setAnimation(PLAYER_ACTION_ROLL);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		if (key->isLeftDown)
			setVx(-vx * 2 / 3);
		if (key->isRightDown)
			setVx(vx * 2 / 3);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);

		if (key->isAttackDown && getDx() < 0.5)
			setPlayerState(PLAYER_STATE_ATTACK);
		break;
	}
		
	//chưa dùng tới
	case PLAYER_STATE_ROLLATTACK:
		setAnimation(PLAYER_ACTION_ROLLATTACK);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}

	PhysicsObject::update(dt);
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
