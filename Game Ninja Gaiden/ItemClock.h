#pragma once
#include "Item.h"
class ItemClock :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemClock();
	~ItemClock();
};

