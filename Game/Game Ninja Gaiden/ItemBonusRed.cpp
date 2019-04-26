#include "ItemBonusRed.h"



void ItemBonusRed::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_PLAYER && getIsRender())
	{
		setAlive(false);
		ScoreBar::getInstance()->increaseScore(1000);
	}
	Item::onIntersect(other);
}

ItemBonusRed::ItemBonusRed()
{
}


ItemBonusRed::~ItemBonusRed()
{
}
