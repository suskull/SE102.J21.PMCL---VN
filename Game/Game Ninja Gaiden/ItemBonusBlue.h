#pragma once
#include "Item.h"
class ItemBonusBlue :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemBonusBlue();
	~ItemBonusBlue();
};

