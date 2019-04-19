#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
#include"Player.h"
#include"Bullet.h"

enum SOLDIER_STATE
{
	SOLDIER_STATE_WAIT,
	SOLDIER_STATE_RUN,
	SOLDIER_STATE_ATTACK
};

enum SOLDIER_ACTION
{
	SOLDIER_ACTION_WAIT,
	SOLDIER_ACTION_RUN,
	SOLDIER_ACTION_ATTACK
};
class Soldier
	: public Enemy
{
	SOLDIER_STATE soldierState;
	bool isAttacking;
	int count;
public:
	void update(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

	void runFollowPlayer();
	void setSoldierState(SOLDIER_STATE soldierState);
	void setIsAttacking(bool isAttacking);
	bool getIsAttacking();
	Soldier();
	~Soldier();
};

