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

void Sword::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
}
