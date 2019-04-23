#pragma once
#include "AdditionalObject.h"
class SubWeapon :
	public AdditionalObject
{
public:
	void onIntersect(MovableRect* other) override;
	SubWeapon();
	~SubWeapon();
};

