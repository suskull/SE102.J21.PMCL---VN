#include "BossEffect.h"
#include"SpriteManager.h"


//
void BossEffect::update(float dt)
{
	setY(getY() + (getHeightCurrentFrame() - getHeight()) / 2);
	setHeight(getHeightCurrentFrame());
	setX(getX() - (getWidthCurrentFrame() - getWidth()) / 2);
	setWidth(getWidthCurrentFrame());

	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	BaseObject::update(dt);
}

void BossEffect::render(Camera* camera)
{

	BaseObject::render(camera);
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
