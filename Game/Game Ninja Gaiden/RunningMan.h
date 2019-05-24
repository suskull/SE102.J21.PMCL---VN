#pragma once
#include "Enemy.h"


class RunningMan :
	public Enemy
{
public:
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	RunningMan();
	~RunningMan();
};

