#include "SittingMan.h"
#include"ScoreBar.h"


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
		if (getX() - Player::getInstance()->getX() < GLOBALS_D("sittingman_player"))
		{
			if (getIsLastFrameAnimationDone())
				count++;
			if (count > GLOBALS_D("sitting_man_time_prepare_attack"))
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
			wp->setVx(getDirection() * GLOBALS_D("sitting_man_bullet_vx"));

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
		if (count > (GLOBALS_D("sitting_man_bullet_count")-1))
		{
			count = 0;
			setSittingManState(SITTINGMAN_STATE_WAIT);
		}
		break;
	}
	Enemy::update(dt);
}

void SittingMan::onIntersect(MovableRect* other)
{

	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		ScoreBar::getInstance()->increaseScore(GLOBALS_D("sitting_man_score"));
	}
	Enemy::onIntersect(other);
}

SittingMan::SittingMan()
{
	setSittingManState(SITTINGMAN_STATE_WAIT);
}


SittingMan::~SittingMan()
{
}
