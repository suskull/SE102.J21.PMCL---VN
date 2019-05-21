#pragma once
#include"PhysicsObject.h"
class Butterfly
	: public PhysicsObject
{
public:
	void onIntersect(MovableRect* other) override;
	Butterfly();
	~Butterfly();
};

