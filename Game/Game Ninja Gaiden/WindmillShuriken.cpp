#include "WindmillShuriken.h"



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
		setAlive(false);
}


