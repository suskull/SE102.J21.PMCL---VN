#pragma once
#include "MovableObject.h"
class Player: public MovableObject
{
	static Player* instance;
public:
	static Player* getInstance();

	void onCollision(PhysicsBox* other, float collisionTime, int nx, int ny) override;
	void update(float dt) override;
	Player();
	~Player();
};

