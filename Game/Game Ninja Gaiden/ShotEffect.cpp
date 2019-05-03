#include "ShotEffect.h"
#include"SpriteManager.h"


void ShotEffect::update(float dt)
{
	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}

ShotEffect::ShotEffect()
{
	setSprite(SPR(SPRITE_SHOT_EFFECT));
	setAy(0);
}


ShotEffect::~ShotEffect()
{
}
