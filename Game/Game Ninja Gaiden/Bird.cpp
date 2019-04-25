#include "Bird.h"
#include <windows.h>

void Bird::setBirdState(BIRD_STATE birdState)
{
	this->birdState = birdState;
}

void Bird::update(float dt)
{
	auto player = Player::getInstance();
	switch (birdState)
	{
	case BIRD_STATE_WAIT:
		if (getX() - player->getX() < 100)
			setBirdState(BIRD_STATE_PREPARE);
		break;
	case BIRD_STATE_PREPARE:
		setVy(player->getY() - getY() - 80);
		setVx(player->getX() - getX() - 80);
		if (player->getY() - getY() > 10 && player->getY() - getY() > 10)
		{
			setAx(80);
			setAy(10);
			setVy(-20);
		}

		// bắt đầu bay
		if (player->getX() - getX() > 40)
		{
			setVx((player->getMidX() - getMidX()) * 2);
			setVy((50 - getMidY()) * 2);
			setDirection(DIRECTION_RIGHT);
			setBirdState(BIRD_STATE_ATTACK1);
		}
		break;
	case BIRD_STATE_ATTACK1:
		if (getMidX() > player->getMidX())
		{
			setAy(-50);
			setAx(-150);
			setBirdState(BIRD_STATE_SLOW_DOWN_RIGHT);
		}
		break;
	case BIRD_STATE_SLOW_DOWN_RIGHT:
		followPlayer();
		if (getMidY() >= 55)
		{
			setVy(-50);
			setVx(50);
			setBirdState(BIRD_STATE_FLY_DOWN_RIGHT);
		}
		break;
	case BIRD_STATE_FLY_DOWN_RIGHT:
		if (getY() < 20) {
			setVx(-(getMidX() - player->getMidX()) * 2);
			setVy((50 - getMidY()) * 2);
			setBirdState(BIRD_STATE_ATTACK2);
		}
		break;
	case BIRD_STATE_ATTACK2:
		if (getMidX() < player->getMidX())
		{
			setAy(-50);
			setAx(150);
			setBirdState(BIRD_STATE_SLOW_DOWN_LEFT);
		}
		break;
	case BIRD_STATE_SLOW_DOWN_LEFT:
		followPlayer();
		if (getMidY() >= 55)
		{
			setVy(-50);
			setVx(-50);
			setBirdState(BIRD_STATE_FLY_DOWN_LEFT);
		}
		break;
	case BIRD_STATE_FLY_DOWN_LEFT:
		if (getY() < 20 ) {
			setVx((player->getMidX() - getMidX()) * 2);
			setVy((50 - getMidY()) * 2);
			setBirdState(BIRD_STATE_ATTACK1);
		}
		break;
	}

	
	Enemy::update(dt);
}

void Bird::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	//Enemy::onCollision(other, collisionTime, nx, ny);
}

void Bird::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON && getAlive())
		ScoreBar::getInstance()->increaseScore(300);
	Enemy::onIntersect(other);
}

void Bird::followPlayer()
{
	auto player = Player::getInstance();
	if (getMidX() > player->getMidX())
		setDirection(DIRECTION_LEFT);
	else
		setDirection(DIRECTION_RIGHT);
}

Bird::Bird()
{
	setAy(0);
	setBirdState(BIRD_STATE_WAIT);
}


Bird::~Bird()
{
}
