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
			setAnimation(SOLDIER_ACTION_RUN);
			setSoldierState(SOLDIER_STATE_RUN);
		}
	
		break;
	case SOLDIER_STATE_RUN:

		if (getX() - player->getX() < 100)
		{
			
			
			setSoldierState(SOLDIER_STATE_ATTACK);
			Bullet* bl = new Bullet();
			bl->setX(getX() + (getDirection() * 20));
			bl->setY(getY() - 9);
			bl->setDirection(getDirection());
			bl->setAx(getDirection() * 15);

		}

		break;
	case SOLDIER_STATE_ATTACK:

		setVx(0);
		setAnimation(SOLDIER_ACTION_ATTACK);

		Enemy::update(dt);

		if (getX() - player->getX() > 50)
			setSoldierState(SOLDIER_STATE_RUN);

		break;
	}

	/*if (getVx() > 0)
		setDirection(DIRECTION_RIGHT);
	else
		setDirection(DIRECTION_LEFT);*/
	Enemy::update(dt);

}

void Soldier::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Soldier::setSoldierState(SOLDIER_STATE soldierState)
{
	this->soldierState = soldierState;
}

Soldier::Soldier()
{
	setAy(0);
	setAnimation(SOLDIER_ACTION_WAIT);
	setSoldierState(SOLDIER_STATE_WAIT);
}


Soldier::~Soldier()
{
}
