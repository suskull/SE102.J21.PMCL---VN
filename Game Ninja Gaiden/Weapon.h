#pragma once
#include "AdditionalObject.h"
class Weapon :
	public AdditionalObject
{
public:
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	Weapon();
	~Weapon();
};

