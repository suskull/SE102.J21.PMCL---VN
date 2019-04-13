#pragma once
#include"AdditionalObject.h"

class Shuriken :
	public AdditionalObject
{
	static Shuriken* instance;
public:
	static Shuriken* getInstance();
	void update(float dt) override;
	//void onIntersect(MovableRect* other) override;
	Shuriken();
	~Shuriken();
};