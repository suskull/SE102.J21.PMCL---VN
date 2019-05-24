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
		ScoreBar::getInstance()->setPlayerHealth(GLOBALS_D("item_restore_physical_strenght"));
		Item::onIntersect(other);
	}
	
}
