#include "ItemShuriken.h"



void ItemShuriken::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
		Player::getInstance()->setCurrentSubWeapon(SUBWEAPON_SHURIKEN);
	Item::onIntersect(other);
}

ItemShuriken::ItemShuriken()
{
}


ItemShuriken::~ItemShuriken()
{
}
