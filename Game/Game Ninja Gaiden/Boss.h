#pragma once
#include "Enemy.h"
#include"Weapon.h"

enum BOSS_STATE
{
	BOSS_STATE_WAIT,
	BOSS_STATE_JUMP
};

enum BOSS_ACTION
{
	BOSS_ACTION_STAND,
	BOSS_ACTION_JUMP
};

class Boss :
	public Enemy
{
	BOSS_STATE bossState;
	bool isJumpping;
	int count;
public:
	void setBossState(BOSS_STATE bossState);
	virtual void setDirectionFollowPlayer();
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void update(float dt) override;
	Boss();
	~Boss();
};

