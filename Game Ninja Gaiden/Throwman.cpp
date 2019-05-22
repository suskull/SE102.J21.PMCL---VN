#include "Throwman.h"

#include"Knife.h"


void Throwman::update(float dt)
{
	if (!getAlive())
		return;
	auto player = Player::getInstance();

	switch (throwmanState) {
	case THROWMAN_STATE_WAIT:
		count = 0;
		setVx(-10);
		isGoingForward = true;
		setThrowmanState(THROWMAN_STATE_RUN);
		break;
	case THROWMAN_STATE_RUN:
		setAnimation(THROWMAN_ACTION_RUN);
		isAttacking = false;
		if (isGoingForward)
			setVx(-10);
		else setVx(10);
		
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > 5)
		{
			count = 0;
			setThrowmanState(THROWMAN_STATE_ATTACK);
		}
		break;
	case THROWMAN_STATE_ATTACK:
		setVx(0);
		setAnimation(THROWMAN_ACTION_ATTACK);
		if (getIsLastFrameAnimationDone() && !isAttacking)
		{
			Knife* kn = new Knife();
			kn->setX(getX() + (getDirection() * 5));
			kn->setY(getY() + 20);
			kn->setDirection(getDirection());
			kn->setVx(getDirection() * (rand()% 60 + 15));
			kn->setAy(-300);
			kn->setVy(70);
			isAttacking = true;
			count++;
		}
		else
			isAttacking = false;
		if (count > 0)
		{
			count = 0;
			setThrowmanState(THROWMAN_STATE_RUN);
		}
		break;
	}

	Enemy::update(dt);
}

void Throwman::setThrowmanState(THROWMAN_STATE throwmanState)
{
	this->throwmanState = throwmanState;
}

void Throwman::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		setIsOnGround(true);
		setVy(0);
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
	if (other->getCollisionType() == COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
		if (nx == 1)
			isGoingForward = false;
		if (nx == -1)
			isGoingForward = true;
	}
	//Enemy::onCollision(other, collisionTime, nx, ny);
}

void Throwman::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON && getAlive())
		ScoreBar::getInstance()->increaseScore(100);
	Enemy::onIntersect(other);
}

Throwman::Throwman()
{
	//setAy(0);
	setAnimation(THROWMAN_ACTION_WAIT);
	setThrowmanState(THROWMAN_STATE_WAIT);
}


Throwman::~Throwman()
{
}
