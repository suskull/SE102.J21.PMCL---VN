#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
#include"Player.h"
enum THROWMAN_STATE {

	THROWMAN_STATE_WAIT,
	THROWMAN_STATE_RUN,
	THROWMAN_STATE_ATTACK
};
enum THROWMAN_ACTION {

	THROWMAN_ACTION_WAIT,
	THROWMAN_ACTION_RUN,
	THROWMAN_ACTION_ATTACK
};

class Throwman
	: public Enemy
{
	THROWMAN_STATE throwmanState;
	bool isAttacking;
	bool isGoingForward;
	int count;
public:
	void update(float dt) override;
	void setThrowmanState(THROWMAN_STATE throwmanState);
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Throwman();
	~Throwman();
};

