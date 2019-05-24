#include "RunningMan.h"
#include"Player.h"
#include"ScoreBar.h"



void RunningMan::update(float dt)
{
	
	setVx(-GLOBALS_D("running_man_vx"));
	Enemy::update(dt);
}

void RunningMan::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
		setVx(-GLOBALS_D("running_man_vx"));
		setVy(-GLOBALS_D("running_man_vy"));
	}
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		ScoreBar::getInstance()->increaseScore(GLOBALS_D("running_man_score"));
	}
	Enemy::onIntersect(other);
}

RunningMan::RunningMan()
{
	setAnimation(0);
}


RunningMan::~RunningMan()
{
}
