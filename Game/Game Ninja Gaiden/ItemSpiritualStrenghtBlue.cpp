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
		ScoreBar::getInstance()->increaseSpiritualStrengh(GLOBALS_D("item_spriritual_strenght_blue_mana"));
	}
		
	Item::onIntersect(other);
}
