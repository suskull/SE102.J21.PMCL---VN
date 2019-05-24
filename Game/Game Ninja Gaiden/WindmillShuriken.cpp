#include "WindmillShuriken.h"
#include "Sound.h"


WindmillShuriken::WindmillShuriken()
{
	setSprite(SPR(SPRITE_WINDMILLSHURIKEN));
	//setPhysicsEnable(true);
	setAy(0);
}


WindmillShuriken::~WindmillShuriken()
{
}

void WindmillShuriken::update(float dt)
{
	auto* player = Player::getInstance();
	
	if ((double)(getX() - (double)player->getX()) > (GLOBALS_D("backbuffer_width") / 4))
		setVx(-150);
	if (((double)player->getX() - (double)getX()) > (GLOBALS_D("backbuffer_width") / 4))
		setVx(150);
	setVy((double)(player->getMidY() - getMidY()));
	BaseObject::update(dt);
}

void WindmillShuriken::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
	{
		Sound::getInstance()->stop("shuriken1");
		setAlive(false);
	}
		

	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && other->getAlive())
	{

		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());

	}

	if (other->getCollisionType() == COLLISION_TYPE_BOSS && getIsLastFrameAnimationDone())
	{
		ScoreBar::getInstance()->decreaseBossHealth(1);
	}


	if (other->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY)
	{
		other->setAlive(false);

		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
		Sound::getInstance()->loadSound("resource/sound/destroyEnemies.wav", "de");
		Sound::getInstance()->play("de", false, 1);
	}
	if (other->getCollisionType() == COLLISION_TYPE_BUTTERFLY && other->getAlive())
	{
		auto explosionEffect = new ExplosionEffect();
		explosionEffect->setLocation(other->getMidX(), other->getMidY());
	}
}


