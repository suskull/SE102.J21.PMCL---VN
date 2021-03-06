#include "Flame.h"



Flame::Flame()
{
	setSprite(SPR(SPRITE_FLAME));
	setAy(0);
	setCollisionType(COLLISION_TYPE_WEAPON);
}


Flame::~Flame()
{
}

void Flame::update(float dt)
{
	auto* player = Player::getInstance();
	if (((double)player->getX() - (double)getX()) > (GLOBALS_D("backbuffer_width") / 4))
		setAlive(false);
	BaseObject::update(dt);
}


