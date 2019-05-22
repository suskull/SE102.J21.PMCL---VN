#include "RunningMan.h"
#include"Player.h"


void RunningMan::setRunningManState(RUNNINGMAN_STATE runningManState)
{
	this->runningManState = runningManState;
}

void RunningMan::onIntersect(MovableRect* other)
{
	if (other->getCollisionType()== COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
			setVx(-100);
			setVy(100);
	}
	Enemy::onIntersect(other);
}

void RunningMan::update(float dt)
{
	switch (runningManState)
	{
	case RUNNINGMAN_STATE_WAIT:
		setAnimation(RUNNINGMAN_ACTION_WAIT);
		if (getX() - Player::getInstance()->getX() < 100)
		{
			setVx(-100);
			setRunningManState(RUNNINGMAN_STATE_RUN);
		}
		break;
	case RUNNINGMAN_STATE_RUN:
		setAnimation(RUNNINGMAN_ACTION_RUN);
		break;
	}
	Enemy::update(dt);
}

RunningMan::RunningMan()
{
	setRunningManState(RUNNINGMAN_STATE_WAIT);
}


RunningMan::~RunningMan()
{
}
