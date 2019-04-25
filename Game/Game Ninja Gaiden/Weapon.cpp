#include "Weapon.h"
#include"ExplosionEffect.h"


void Weapon::update(float dt)
{
	setWidth(getWidthCurrentFrame());
	setHeight(getHeightCurrentFrame());
	BaseObject::update(dt);
}

void Weapon::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && other->getAlive())
	{
		//other->setAlive(false);
		setAlive(false);

		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY)
	{
		other->setAlive(false);
		setAlive(false);

		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
	if (other->getCollisionType() == COLLISION_TYPE_BUTTERFLY && other->getAlive())
	{
		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
}

Weapon::Weapon()
{
	setCollisionType(COLLISION_TYPE_WEAPON);
}


Weapon::~Weapon()
{
}
