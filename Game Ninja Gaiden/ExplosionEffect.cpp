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

void ExplosionEffect::render(Camera* camera)
{
	setY(getY() + (getHeightCurrentFrame() - getHeight())/2);
	setHeight(getHeightCurrentFrame());
	setX(getX() - (getWidthCurrentFrame() - getWidth()) / 2);
	setWidth(getWidthCurrentFrame());
	PhysicsObject::render(camera);
}

ExplosionEffect::ExplosionEffect()
{
	setPhysicsEnable(false);
	setSprite(SPR(SPRITE_INFO_EXPLOSION_EFFECT));
}


ExplosionEffect::~ExplosionEffect()
{
}