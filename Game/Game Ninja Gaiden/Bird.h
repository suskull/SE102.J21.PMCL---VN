#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
#include"Player.h"

enum BIRD_STATE {
	BIRD_STATE_WAIT,
	BIRD_STATE_PREPARE,
	BIRD_STATE_ATTACK1,
	BIRD_STATE_ATTACK2,
	BIRD_STATE_ATTACK3,
	BIRD_STATE_ATTACK4
};
class Bird
	: public Enemy
{
	BIRD_STATE birdState;
public:
	void setBirdState(BIRD_STATE birdState);
	void update(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Bird();
	~Bird();
};

