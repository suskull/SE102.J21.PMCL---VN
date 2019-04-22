#include "SubWeaponSwordMan.h"
#include"SpriteManager.h"
#include"BaseObject.h"

void SubWeaponSwordMan::update(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}

SubWeaponSwordMan::SubWeaponSwordMan()
{
	setSprite(SPR(SPRITE_SUBWEAPON_SWORDMAN));
	setPhysicsEnable(false);
}


SubWeaponSwordMan::~SubWeaponSwordMan()
{
}
