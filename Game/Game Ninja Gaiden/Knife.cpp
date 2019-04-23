#include "Knife.h"



void Knife::update(float dt)
{
	BaseObject::update(dt);
}

void Knife::onIntersect(MovableRect* other)
{
}

Knife::Knife()
{
	setSprite(SPR(SPRITE_KNIFE));
	setAy(0);
	setCollisionType(COLLISION_TYPE_SUBWEAPON_ENEMY);
}


Knife::~Knife()
{
}
