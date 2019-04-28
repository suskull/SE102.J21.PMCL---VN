#pragma once
#include "Item.h"
class ItemWindmillShuriken :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemWindmillShuriken();
	~ItemWindmillShuriken();
};

