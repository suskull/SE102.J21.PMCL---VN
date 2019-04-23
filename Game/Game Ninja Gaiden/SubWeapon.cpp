#include "SubWeapon.h"



void SubWeapon::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && other->getAlive())
	{
		other->setAlive(false);
		setAlive(false);
	}
	if (other->getCollisionType() == COLLISION_TYPE_SUBWEAPON_ENEMY)
	{
		other->setAlive(false);
		setAlive(false);
	}
		
}

SubWeapon::SubWeapon()
{
	setCollisionType(COLLISION_TYPE_WEAPON);
}


SubWeapon::~SubWeapon()
{
}
