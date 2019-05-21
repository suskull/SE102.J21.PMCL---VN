#include "RunningMan.h"
#include"Player.h"


void RunningMan::setRunningManState(RUNNINGMAN_STATE runningManState)
{
	this->runningManState = runningManState;
}

void RunningMan::update(float dt)
{
	switch (runningManState)
	{
	case RUNNINGMAN_STATE_WAIT:
		setAnimation(RUNNINGMAN_ACTION_WAIT);
		if (getX() - Player::getInstance()->getX() < 50)
		{
			setVx(-50);
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
