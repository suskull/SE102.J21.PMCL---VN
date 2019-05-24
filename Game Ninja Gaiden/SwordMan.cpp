#include "SwordMan.h"



void SwordMan::update(float dt)
{
	if (!getAlive())
		return;
	auto player = Player::getInstance();

	switch (swordmanState) {
	case SWORDMAN_STATE_WAIT:
		/*if (getX() - player->getX() < (GLOBALS_D("backbuffer_width") / 2))
		{
			setVx(-50);
			setSwordmanState(SWORDMAN_STATE_RUN);
		}*/
		break;
	case SWORDMAN_STATE_RUN:
		setVx(-GLOBALS_D("swordman_vx"));
		break;
	}

	if (getVx() > 0)
		setDirection(DIRECTION_RIGHT);
	else
		setDirection(DIRECTION_LEFT);

	Enemy::update(dt);
}

void SwordMan::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void SwordMan::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON && getAlive())
		ScoreBar::getInstance()->increaseScore(GLOBALS_D("swordman_score"));

	if (other->getCollisionType() == COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
		if (getDx() < 0 && getIsLastFrameAnimationDone())
		{
			setVx(abs(getVx()));
		}
		if (getDx() > 0 && getIsLastFrameAnimationDone())
			setVx(-abs(getVx()));
	}

	Enemy::onIntersect(other);
}

void SwordMan::setSwordmanState(SWORDMAN_STATE swordmanState)
{
	this->swordmanState = swordmanState;
}

SwordMan::SwordMan()
{
	setSwordmanState(SWORDMAN_STATE_RUN);
}


SwordMan::~SwordMan()
{

}
