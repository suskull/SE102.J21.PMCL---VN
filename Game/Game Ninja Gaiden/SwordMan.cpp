#include "SwordMan.h"



void SwordMan::update(float dt)
{

	auto player = Player::getInstance();

	switch (swordmanState) {
	case SWORDMAN_STATE_WAIT:
		if (getX() - player->getX() < (GLOBALS_D("backbuffer_width") / 2))
		{
			setVx(-100);
			setSwordmanState(SWORDMAN_STATE_RUN);
		}
		break;
	case SWORDMAN_STATE_RUN:
		if (getDirection() == DIRECTION_LEFT)
		{
			setX(getX() + getWidth() - getWidthCurrentFrame());
			setWidth(getWidthCurrentFrame());
		}
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

	if (other->getCollisionType() == COLLISION_TYPE_GROUND && nx == 1) {
		setVx(-getVx());
		Enemy::onCollision(other, collisionTime, nx, ny);
	}
}

void SwordMan::setSwordmanState(SWORDMAN_STATE swordmanState)
{
	this->swordmanState = swordmanState;
}

SwordMan::SwordMan()
{
	setAy(0);
	setSwordmanState(SWORDMAN_STATE_WAIT);
}


SwordMan::~SwordMan()
{

}
