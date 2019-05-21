#pragma once
#include "Item.h"
class ItemBonusRed :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemBonusRed();
	~ItemBonusRed();
};

