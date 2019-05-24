#include "Panther.h"
#include"GameConfiguration.h"



void Panther::update(float dt)
{
	
	auto player = Player::getInstance();

	switch (pantherState) {
	case PATHER_STATE_WAIT:
			setVx(-vx);
			setPantherState(PATHER_STATE_RUN);
		break;
	case PATHER_STATE_RUN:
		break;
	}
		
	if (getVx() > 0)
		setDirection(DIRECTION_RIGHT);
	else
		setDirection(DIRECTION_LEFT);
	Enemy::update(dt);
}

void Panther::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Panther::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON && getAlive())
	{
		ScoreBar::getInstance()->increaseScore(score);
	}
	Enemy::onIntersect(other);
}

void Panther::setPantherState(PANTHER_STATE pantherState)
{
	this->pantherState = pantherState;
}

Panther::Panther()
{
	setPantherState(PATHER_STATE_WAIT);
}


Panther::~Panther()
{
}
