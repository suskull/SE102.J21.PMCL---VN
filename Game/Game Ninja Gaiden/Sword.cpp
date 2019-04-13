#include "Sword.h"
#include "SpriteManager.h"
#include"Player.h"

Sword* Sword::instance = 0;
Sword* Sword::getInstance()
{
	if (instance == 0)
	{
		instance = new Sword();
	};
	return instance;
}

Sword::Sword()
{
	setSprite(SPR(SPRITE_SWORD));
	(0);
	setPhysicsEnable(false);
	setAlive(false);
}


Sword::~Sword()
{
}

void Sword::update(float dt)
{
	BaseObject::update(dt);
}

void Sword::render(Camera* camera)
{
	auto player = Player::getInstance();
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
		
	
	setDirection(player->getDirection());
	PhysicsObject::render(camera);
}
