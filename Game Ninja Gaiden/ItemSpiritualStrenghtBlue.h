#pragma once
#include "Item.h"
class ItemSpiritualStrenghtBlue :
	public Item
{
public:
	ItemSpiritualStrenghtBlue();
	~ItemSpiritualStrenghtBlue();
	void onIntersect(MovableRect* other) override;
};

