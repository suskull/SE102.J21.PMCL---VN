#include "ItemClock.h"
#include"Sound.h"


void ItemClock::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
	
		Player::getInstance()->setMakeEnemyPause(true);
		Sound::getInstance()->loadSound("resource/sound/clock.wav", "clock");
		Sound::getInstance()->play("clock", false, 1);
		
	}
	Item::onIntersect(other);
}

ItemClock::ItemClock()
{
}


ItemClock::~ItemClock()
{
}
