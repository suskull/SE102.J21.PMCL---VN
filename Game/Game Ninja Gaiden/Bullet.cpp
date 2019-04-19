#include "Bullet.h"



void Bullet::update(float dt)
{
	BaseObject::update(dt);
}

void Bullet::onIntersect(MovableRect* other)
{
}

Bullet::Bullet()
{
	setCollisionType(COLLISION_TYPE_ENEMY);
	setSprite(SPR(SPRITE_BULLET));
	setAy(0);
}


Bullet::~Bullet()
{
}
