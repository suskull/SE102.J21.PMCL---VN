#include "ItemShuriken.h"



void ItemShuriken::onCollision(MovableRect* other, float collsionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
		Player::getInstance()->setCurrentSubWeapon(SUBWEAPON_SHURIKEN);
	Item::onCollision(other, collsionTime, nx, ny);
}

ItemShuriken::ItemShuriken()
{
}


ItemShuriken::~ItemShuriken()
{
}
