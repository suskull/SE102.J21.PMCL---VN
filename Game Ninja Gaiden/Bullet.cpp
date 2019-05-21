#include "Bullet.h"





void Bullet::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		setAlive(false);
		other->setAlive(false);
	}
}

Bullet::Bullet()
{
	setCollisionType(COLLISION_TYPE_WEAPON_ENEMY);
	setSprite(SPR(SPRITE_BULLET));
	setAy(0);
}


Bullet::~Bullet()
{
}
