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
		if (player->getX() - getX() > 40)
		{
			setDx(0);
			setDy(0);
			setVx(0);
			setVy(0);
			setDirection(DIRECTION_RIGHT);
			setBirdState(BIRD_STATE_ATTACK1);
		}
		break;
	case BIRD_STATE_ATTACK1:
		if (getX() <= player->getX() - player->getHeight())
		{
			// bắt đầu bay
			setVx(160);
			setVy(60);
			setAx(40);
			setAy(10);
		}
		else
		{
			//khi X chim > X player
			
			if (getY() - player->getY() < 3)
			{
				setAx(-200);
				setAy(-20);
			}
			else
			{
				setVy(-10);
				setAy(0);
				setVx(5);
			}
			if (getX() > player->getX() + 60)
			{
				setDx(0);
				setDy(0);
			}
		}

		/*if (getX() - player->getX() > 40) {
			setDx(0);
			setDy(0);
			setDirection(DIRECTION_RIGHT);
			setBirdState(BIRD_STATE_ATTACK2);
		}*/
		break;
	case BIRD_STATE_ATTACK2:
		break;
	}
	Enemy::update(dt);
}

void Bird::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	//Enemy::onCollision(other, collisionTime, nx, ny);
}

Bird::Bird()
{
	setAy(0);
	setBirdState(BIRD_STATE_WAIT);
}


Bird::~Bird()
{
}
