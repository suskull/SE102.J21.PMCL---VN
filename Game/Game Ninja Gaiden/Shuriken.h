#pragma once
#include"Weapon.h"

class Shuriken :
	public Weapon
{
	static Shuriken* instance;
public:
	static Shuriken* getInstance();
	Shuriken();
	~Shuriken();
};