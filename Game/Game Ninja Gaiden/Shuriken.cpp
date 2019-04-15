#include "Shuriken.h"
#include"Player.h"
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
	auto* player = Player::getInstance();

	if ((double)(getX() - (double)player->getX()) > (GLOBALS_D("backbuffer_width") / 2))
		setAlive(false);

	if (((double)player->getX() - (double)getX()) > (GLOBALS_D("backbuffer_width") / 2))
		setAlive(false);
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