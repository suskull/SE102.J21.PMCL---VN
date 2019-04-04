#pragma once
#include "Rect.h"
class PhysicsBox :
	public Rect
{
	float dx, dy;
	float vx, vy, ax, ay;
	bool physicsEnable;
public:

	void moveX(float dx);
	void moveY(float dy);
	void move(float dx, float dy);

	virtual void setDx(float dx);
	virtual void setDy(float dy);

	float getDx();
	float getDy();

	virtual void setVx(float vx);
	void setVy(float vy);
	void setAx(float ax);
	void setAy(float ay);
	float getVx();
	float getVy();
	float getAx();
	float getAy();

	bool isPhysicsEnable();
	void setPhysicsEnable(bool physicsEnable);

	void updatePhysics(float dt);

	PhysicsBox();
	~PhysicsBox();
};
