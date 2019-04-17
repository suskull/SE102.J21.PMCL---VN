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
	if (other->getCollisionType() == COLLISION_TYPE_GROUND && nx == 1) {
		setVx(-getVx());
		Enemy::onCollision(other, collisionTime, nx, ny);
	}
}

void Panther::setPantherState(PANTHER_STATE pantherState)
{
	this->pantherState = pantherState;
}

Panther::Panther()
{
	setAy(0);
	setPantherState(PATHER_STATE_WAIT);
}


Panther::~Panther()
{
}
