#include "Soldier.h"





void Soldier::update(float dt)
{
	auto player = Player::getInstance();

	switch (soldierState) {
	case SOLDIER_STATE_WAIT:

		setAnimation(SOLDIER_ACTION_WAIT);

		if (getX() - player->getX() < (GLOBALS_D("backbuffer_width") / 2))
		{
			setVx(-50);
			count = 0;
			setSoldierState(SOLDIER_STATE_RUN);
		}
		break;
	case SOLDIER_STATE_RUN:
		setAnimation(SOLDIER_ACTION_RUN);
		isAttacking = false;
		runFollowPlayer();
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > 5)
		{
			count = 0;
			setSoldierState(SOLDIER_STATE_ATTACK);
		}
		break;
	case SOLDIER_STATE_ATTACK:
		setDx(0);
		setVx(0);
		setAnimation(SOLDIER_ACTION_ATTACK);
		if (getIsLastFrameAnimationDone() && !isAttacking)
		{
			Bullet* bl = new Bullet();
			bl->setX(getX() + (getDirection() * 20));
			bl->setY(getY() - 9);
			bl->setDirection(getDirection());
			bl->setVx(getDirection() * 60);
			isAttacking = true;
			count++;
		}
		else 
			isAttacking = false;
		//bắn đủ 3 viên thì quay lại Run
		if (count > 2)
		{
			count = 0;
			setSoldierState(SOLDIER_STATE_RUN);
		}
		break;
	}

	if (player->getMidX() > getMidX())
		setDirection(DIRECTION_RIGHT);
	else
		setDirection(DIRECTION_LEFT);
	Enemy::update(dt);

}

void Soldier::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Soldier::runFollowPlayer()
{
	auto player = Player::getInstance();
	if (getMidX() > player->getMidX())
	{
		setDirection(DIRECTION_LEFT);
		setVx(-20);
	}
	else
	{
		setDirection(DIRECTION_RIGHT);
		setVx(20);
	}
}

void Soldier::setSoldierState(SOLDIER_STATE soldierState)
{
	this->soldierState = soldierState;
}

void Soldier::setIsAttacking(bool isAttacking)
{
	this->isAttacking = isAttacking;
}

bool Soldier::getIsAttacking()
{
	return isAttacking;
}

Soldier::Soldier()
{
	//setAy(0);
	setAnimation(SOLDIER_ACTION_WAIT);
	setSoldierState(SOLDIER_STATE_WAIT);
}


Soldier::~Soldier()
{
}
