#pragma once
#include "Item.h"
class ItemFireWheel :
	public Item
{
public:
	void onCollision(MovableRect* other, float collsionTime, int nx, int ny) override;
	ItemFireWheel();
	~ItemFireWheel();
};

