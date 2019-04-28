#include "ItemFireWheel.h"





void ItemFireWheel::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		Player::getInstance()->setCurrentSubWeapon(SUBWEAPON_FIREWHEEL);
	}
	Item::onIntersect(other);
}

ItemFireWheel::ItemFireWheel()
{
}


ItemFireWheel::~ItemFireWheel()
{
}
