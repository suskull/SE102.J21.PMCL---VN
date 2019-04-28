#include "ItemBonusBlue.h"



void ItemBonusBlue::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		ScoreBar::getInstance()->increaseScore(500);
	}
	Item::onIntersect(other);
}

ItemBonusBlue::ItemBonusBlue()
{
}


ItemBonusBlue::~ItemBonusBlue()
{
}
