#pragma once
#include "Item.h"
class ItemSpiritualStrengtRed :
	public Item
{
public:
	ItemSpiritualStrengtRed();
	~ItemSpiritualStrengtRed();
	void onIntersect(MovableRect* other) override;
};

