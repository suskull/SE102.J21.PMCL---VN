#pragma once
#include "Item.h"
class ItemShuriken :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemShuriken();
	~ItemShuriken();
};

