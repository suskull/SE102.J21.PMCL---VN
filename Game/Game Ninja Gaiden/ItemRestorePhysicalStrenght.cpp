#include "ItemRestorePhysicalStrenght.h"



ItemRestorePhysicalStrenght::ItemRestorePhysicalStrenght()
{
}


ItemRestorePhysicalStrenght::~ItemRestorePhysicalStrenght()
{
}

void ItemRestorePhysicalStrenght::onIntersect(MovableRect* other)
{
	ScoreBar::getInstance()->setPlayerHealth(16);
	Item::onIntersect(other);
}
