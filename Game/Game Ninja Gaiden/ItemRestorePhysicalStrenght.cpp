#include "ItemRestorePhysicalStrenght.h"



ItemRestorePhysicalStrenght::ItemRestorePhysicalStrenght()
{
}


ItemRestorePhysicalStrenght::~ItemRestorePhysicalStrenght()
{
}

void ItemRestorePhysicalStrenght::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		ScoreBar::getInstance()->setPlayerHealth(16);
		Item::onIntersect(other);
	}
	
}
