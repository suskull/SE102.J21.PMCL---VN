#include "ItemSpiritualStrenghtBlue.h"



ItemSpiritualStrenghtBlue::ItemSpiritualStrenghtBlue()
{
}


ItemSpiritualStrenghtBlue::~ItemSpiritualStrenghtBlue()
{
}

void ItemSpiritualStrenghtBlue::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		ScoreBar::getInstance()->increaseSpiritualStrengh(5);
	}
		
	Item::onIntersect(other);
}
