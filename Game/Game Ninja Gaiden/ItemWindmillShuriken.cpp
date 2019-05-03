#include "ItemWindmillShuriken.h"



void ItemWindmillShuriken::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
		Player::getInstance()->setCurrentSubWeapon(SUBWEAPON_WINDMILLSHURIKEN);
	Item::onIntersect(other);
}

ItemWindmillShuriken::ItemWindmillShuriken()
{
}


ItemWindmillShuriken::~ItemWindmillShuriken()
{
}
