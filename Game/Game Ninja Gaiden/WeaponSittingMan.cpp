#include "WeaponSittingMan.h"
#include"SpriteManager.h"


WeaponSittingMan::WeaponSittingMan()
{
	setSprite(SPR(SPRITE_WEAPON_SITTINGMAN));
	setAy(0);
	setCollisionType(COLLISION_TYPE_WEAPON_ENEMY);
}


WeaponSittingMan::~WeaponSittingMan()
{
}
