#include "RedBird.h"



void RedBird::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
		setAlive(false);
}

RedBird::RedBird()
{
	setCollisionType(COLLISION_TYPE_BUTTERFLY);
	setDirection(DIRECTION_RIGHT);
	setAy(0);
}


RedBird::~RedBird()
{
}
