#include "ItemFireWheel.h"



void ItemFireWheel::onCollision(MovableRect* other, float collsionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER)
		Player::getInstance()->setCurrentSubWeapon(SUBWEAPON_FIREWHEEL);
	Item::onCollision(other, collsionTime, nx, ny);
}

ItemFireWheel::ItemFireWheel()
{
}


ItemFireWheel::~ItemFireWheel()
{
}
