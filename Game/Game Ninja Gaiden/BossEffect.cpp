#include "BossEffect.h"
#include"SpriteManager.h"


//
void BossEffect::update(float dt)
{
	int count = 0;
	count++;
	
	if (count == 5)
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}






BossEffect::BossEffect()
{
	setSprite(SPR(SPRITE_BOSS_EFFECT));
	setPhysicsEnable(false);
	//setCollisionType(COLLISION)
}


BossEffect::~BossEffect()
{
}
