#include "ExplosionEffect.h"
#include "SpriteManager.h"

void ExplosionEffect::update(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}

ExplosionEffect::ExplosionEffect()
{
	setPhysicsEnable(false);
	setSprite(SPR(SPRITE_INFO_EXPLOSION_EFFECT));
}


ExplosionEffect::~ExplosionEffect()
{
}