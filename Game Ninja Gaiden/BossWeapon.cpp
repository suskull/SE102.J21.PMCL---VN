#include "BossWeapon.h"



void BossWeapon::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		setAlive(false);
		other->setAlive(false);
	}
}

BossWeapon::BossWeapon()
{
	setCollisionType(COLLISION_TYPE_WEAPON_ENEMY);
	setSprite(SPR(SPRITE_BOSS_WEAPON));
	setAy(0);
}


BossWeapon::~BossWeapon()
{
}
