#pragma once
#include "Item.h"
class ItemShuriken :
	public Item
{
public:
	void onCollision(MovableRect* other, float collsionTime, int nx, int ny) override;
	ItemShuriken();
	~ItemShuriken();
};

