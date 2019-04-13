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
void Shuriken::update(float dt)
{
	BaseObject::update(dt);
}

Shuriken::Shuriken()
{
	setSprite(SPR(SPRITE_INFO_SHURIKEN));
	setAy(0);
}
Shuriken::~Shuriken()
{

}