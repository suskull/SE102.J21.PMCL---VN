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
		ScoreBar::getInstance()->increaseSpiritualStrengh(GLOBALS_D("item_spriritual_strenght_red_mana"));
	}

	Item::onIntersect(other);
}
