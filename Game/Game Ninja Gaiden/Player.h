#pragma once
#include "PhysicsObject.h"
class Player: public PhysicsObject
{
	static Player* instance;
public:
	static Player* getInstance();

	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	//void update(float dt) override;
	Player();
	~Player();
};

