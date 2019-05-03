#include "Shuriken.h"

#include"SpriteManager.h"
Shuriken* Shuriken::instance = 0;
Shuriken* Shuriken::getInstance()
{
	if (instance == 0)
	{
		instance = new Shuriken();
	}
	return instance;
}


Shuriken::Shuriken()
{
	setCollisionType(COLLISION_TYPE_WEAPON);
	setSprite(SPR(SPRITE_INFO_SHURIKEN));
	setAy(0);
}
Shuriken::~Shuriken()
{

}