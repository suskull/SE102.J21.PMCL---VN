#pragma once
#include "Item.h"
class ItemRestorePhysicalStrenght :
	public Item
{
public:
	ItemRestorePhysicalStrenght();
	~ItemRestorePhysicalStrenght();
	void onIntersect(MovableRect* other) override;
};

