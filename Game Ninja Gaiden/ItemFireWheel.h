#pragma once
#include "Item.h"
class ItemFireWheel :
	public Item
{
public:
	void onIntersect(MovableRect* other) override;
	ItemFireWheel();
	~ItemFireWheel();
};

