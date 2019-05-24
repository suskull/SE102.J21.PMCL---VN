#include "ItemBonusBlue.h"



void ItemBonusBlue::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		ScoreBar::getInstance()->increaseScore(GLOBALS_D("item_bonus_blue_score"));
	}
	Item::onIntersect(other);
}

ItemBonusBlue::ItemBonusBlue()
{
}


ItemBonusBlue::~ItemBonusBlue()
{
}
