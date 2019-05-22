#include "RunningMan.h"
#include"Player.h"




void RunningMan::update(float dt)
{
	
	setVx(-100);
	Enemy::update(dt);
}

void RunningMan::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
		setVx(-100);
		setVy(100);
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
