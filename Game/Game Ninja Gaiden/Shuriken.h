#pragma once
#include"SubWeapon.h"

class Shuriken :
	public SubWeapon
{
	static Shuriken* instance;
public:
	static Shuriken* getInstance();
	void update(float dt) override;
	Shuriken();
	~Shuriken();
};