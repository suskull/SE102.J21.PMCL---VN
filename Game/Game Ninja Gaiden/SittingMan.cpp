#include "SittingMan.h"



void SittingMan::setSittingManState(SITTINGMAN_STATE sittingManState)
{
	this->sittingManState = sittingManState;
}

void SittingMan::update(float dt)
{
	switch (sittingManState)
	{
	case SITTINGMAN_STATE_WAIT:
		setAnimation(SITTINGMAN_ACTION_WAIT);
		isAttacking = false;
		if (getX() - Player::getInstance()->getX() < 50)
		{
			if (getIsLastFrameAnimationDone())
				count++;
			if (count > 5)
			{
				count = 0;
				setSittingManState(SITTINGMAN_STATE_ATTACK);
			}
		}
		break;
	case SITTINGMAN_STATE_ATTACK:
		setAnimation(SITTINGMAN_ACTION_ATTACK);
		if (getIsLastFrameAnimationDone() && !isAttacking && getAlive())
		{
			WeaponSittingMan* wp = new WeaponSittingMan();
			wp->setX(getX() + (getDirection() * 8));
			wp->setY(getY() - 1);
			wp->setDirection(getDirection());
			wp->setVx(getDirection() * 60);

			ShotEffect* se = new ShotEffect();
			se->setX(getX() + (getDirection() * 8));
			se->setY(getY() + 5);
			se->setDirection(getDirection());

			isAttacking = true;
			count++;
		}
		else
			isAttacking = false;
		//bắn 1 viên thì quay lại Wait
		if (count > 0)
		{
			count = 0;
			setSittingManState(SITTINGMAN_STATE_WAIT);
		}
		break;
	}
	Enemy::update(dt);
}

SittingMan::SittingMan()
{
}


SittingMan::~SittingMan()
{
}
