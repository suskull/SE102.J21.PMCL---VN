#include "ItemBonusRed.h"



void ItemBonusRed::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		ScoreBar::getInstance()->increaseScore(GLOBALS_D("item_bonus_red_score"));
	}
	Item::onIntersect(other);
}

ItemBonusRed::ItemBonusRed()
{
}


ItemBonusRed::~ItemBonusRed()
{
}
