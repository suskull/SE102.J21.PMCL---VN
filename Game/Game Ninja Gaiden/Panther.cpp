#include "Panther.h"
#include"GameConfiguration.h"



void Panther::update(float dt)
{
	auto player = Player::getInstance();

	switch (pantherState) {
	case PATHER_STATE_WAIT:
		if (getX() - player->getX() < (GLOBALS_D("backbuffer_width") / 2))
		{
			setVx(-100);
			setPantherState(PATHER_STATE_RUN);
		}
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
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
		ScoreBar::getInstance()->increaseScore(100);
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
