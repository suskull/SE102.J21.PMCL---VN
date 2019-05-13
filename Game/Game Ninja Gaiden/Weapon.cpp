#include "Weapon.h"
#include"ExplosionEffect.h"
#include"ScoreBar.h"
#include"Bullet.h"


void Weapon::update(float dt)
{
	setWidth(getWidthCurrentFrame());
	setHeight(getHeightCurrentFrame());
	BaseObject::update(dt);
}

void Weapon::onIntersect(MovableRect* other)
{
	if (!getAlive())
		return;
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && other->getAlive())
	{
		setAlive(false);

		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}

	if (other->getCollisionType() == COLLISION_TYPE_BOSS )
	{
		ScoreBar::getInstance()->decreaseBossHealth(1);
		//setAlive(false);

		auto bullet = new Bullet();
		bullet->setX(getX());
		bullet->setY(getY());
		/*auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());*/
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
