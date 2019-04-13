#pragma once
#include "BaseObject.h"
#include"GameConfiguration.h"

class PhysicsObject :
	public BaseObject
{
	float ax, ay, vx, vy;
	bool physicsEnable;
	bool isOnGround;

public:
	float getAx();
	float getAy();
	float getVx();
	float getVy();
	virtual void setAx(float ax);
	virtual void setAy(float ay);
	virtual void setVx(float vx);
	virtual void setVy(float vy);

	bool getPhysicsEnable();
	void setPhysicsEnable(bool physicsEnable);

	bool getIsOnGround();
	void setIsOnGround(bool isOnGround);

	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

	void onUpdate(float dt) override;
	//void update(float dt) override {}

	PhysicsObject();
	~PhysicsObject();
};

