#include "Item.h"



Item::Item()
{
	setPhysicsEnable(false);
	setIsRender(false);
}


Item::~Item()
{
}

void Item::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		setPhysicsEnable(true);
		setIsRender(true);
	}
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		setAlive(false);
	}
}

void Item::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
		preventMovementWhenCollision(collisionTime, nx, ny);
}

