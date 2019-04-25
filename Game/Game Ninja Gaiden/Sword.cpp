#include "Sword.h"
#include "SpriteManager.h"
#include"Player.h"


Sword::Sword()
{
	setSprite(SPR(SPRITE_SWORD));
	setPhysicsEnable(false);
	setAlive(false);
	setCollisionType(COLLISION_TYPE_WEAPON);
}


Sword::~Sword()
{
}

void Sword::update(float dt)
{
	auto player = Player::getInstance();
	auto frameIndex = player->getFrameAnimation();
	switch (frameIndex)
	{
	case 0:
		setFrameAnimation(0);
		break;
	case 1:
		setFrameAnimation(1);
		break;
	case 2:
		setFrameAnimation(2);
		break;
	}

	if (getIsLastFrameAnimationDone())
	{
		setAlive(false);
	}
	Weapon::update(dt);
}

void Sword::render(Camera* camera)
{
	auto player = Player::getInstance();
	setDirection(player->getDirection());

	setHeight(getHeightCurrentFrame());
	setWidth(getWidthCurrentFrame());
	
	if (getDirection() == DIRECTION_RIGHT)
	{
		setX(player->getX() + player->getWidthCurrentFrame());
		setY(player->getY() - 3);
	}
	else
	{
		setX(player->getX() - getWidthCurrentFrame());
		setY(player->getY() - 3);
	}
		
	BaseObject::render(camera);
}

void Sword::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && other->getAlive())
	{
		other->setAlive(false);

		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY)
	{
		other->setAlive(false);
		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
	if (other->getCollisionType() == COLLISION_TYPE_BUTTERFLY && other->getAlive())
	{
		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
}

