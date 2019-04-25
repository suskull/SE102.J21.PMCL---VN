#include "ItemSpiritualStrengtRed.h"



ItemSpiritualStrengtRed::ItemSpiritualStrengtRed()
{
}


ItemSpiritualStrengtRed::~ItemSpiritualStrengtRed()
{
}

void ItemSpiritualStrengtRed::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		ScoreBar::getInstance()->increaseSpiritualStrengh(10);
		setAlive(false);
	}

	Item::onIntersect(other);
}
