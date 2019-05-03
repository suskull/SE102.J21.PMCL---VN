#pragma once
#include"AdditionalObject.h"
class SubWeaponSwordMan
	:public AdditionalObject
{
public:
	void update(float dt) override;
	SubWeaponSwordMan();
	~SubWeaponSwordMan();
};

