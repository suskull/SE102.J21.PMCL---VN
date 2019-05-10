#include "Boss.h"
#include"SpriteManager.h"
#include "Player.h"


void Boss::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void Boss::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - getMidX() < 0)
	{
		setDirection(DIRECTION_LEFT);
	}
	else
	{
		setDirection(DIRECTION_RIGHT);
	}
}

void Boss::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	//isJumpping = false;
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		setIsOnGround(true);
		setVy(0);
		preventMovementWhenCollision(collisionTime, nx, ny);
		setDirectionFollowPlayer();

	}
}

void Boss::onIntersect(MovableRect* other)
{


	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		ScoreBar::getInstance()->decreaseBossHealth(1);

	}


	if (ScoreBar::getInstance()->getBossHealth() == 0)
	{
		setAlive(false);

	}
}

void Boss::update(float dt)
{
	auto player = Player::getInstance();

	switch (bossState)
	{
	case BOSS_STATE_WAIT:
		setAnimation(BOSS_ACTION_STAND);
		/*	if (abs(getX() - player->getX())  < 50 );*/

		count == 0;
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > 5)
		{
			setVy(300);
			setVx(getDirection() * 120);
			setBossState(BOSS_STATE_JUMP);
			count = 0;

		}
		break;
	case BOSS_STATE_JUMP:
		setAnimation(BOSS_ACTION_JUMP);

		if (getIsOnGround())
		{
			setBossState(BOSS_STATE_WAIT);
			setAnimation(BOSS_ACTION_STAND);
		}
		break;
	}
	Enemy::update(dt);
}

Boss::Boss()
{
	setSprite(SPR(SPRITE_BOSS));
	//setCollisionType(COLLISION_TYPE_BOSS);
}


Boss::~Boss()
{
}
