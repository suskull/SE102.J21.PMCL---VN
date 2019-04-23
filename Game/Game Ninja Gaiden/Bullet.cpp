#include "Bullet.h"



void Bullet::update(float dt)
{
	BaseObject::update(dt);
}

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
	setCollisionType(COLLISION_TYPE_SUBWEAPON_ENEMY);
	setSprite(SPR(SPRITE_BULLET));
	setAy(0);
}


Bullet::~Bullet()
{
}
