#pragma once
#include"PhysicsObject.h"
class Enemy
	:public PhysicsObject
{
public:
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void render(Camera* camera) override;
	Enemy();
	~Enemy();
};

