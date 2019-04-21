#include "Butterfly.h"



void Butterfly::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
		setAlive(false);
}

Butterfly::Butterfly()
{
	setCollisionType(COLLISION_TYPE_BUTTERFLY);
	setDirection(DIRECTION_RIGHT);
	setAy(0);
}


Butterfly::~Butterfly()
{
}
