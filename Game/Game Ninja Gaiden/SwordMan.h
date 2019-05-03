#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
#include"Player.h"

enum SWORDMAN_STATE {

	SWORDMAN_STATE_WAIT,
	SWORDMAN_STATE_RUN
};
class SwordMan
	: public Enemy
{
	SWORDMAN_STATE swordmanState;
public:
	void update(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;

	void setSwordmanState(SWORDMAN_STATE swordmanState);
	SwordMan();
	~SwordMan();
};

