#pragma once
#include"BaseObject.h"
class MovableObject 
	: public BaseObject
{
	// doi tuong co dang o tren mat dat hay khong
	bool onGround;
	float dt;
public:
	float getDt();
	void setIsOnGround(bool onGround);
	void onCollision(PhysicsBox* other, int nx, int ny, float collisionTime);
	virtual void update(float dt) override;
	bool isOnGround();
	MovableObject();
	~MovableObject();
};

