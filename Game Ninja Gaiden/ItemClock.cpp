#include "ItemClock.h"
#include"Sound.h"


void ItemClock::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		
		Player::getInstance()->setMakeEnemyPause(true);
		
		
	}
	Item::onIntersect(other);
}

ItemClock::ItemClock()
{
}


ItemClock::~ItemClock()
{
}
