#pragma once
#include "Enemy.h"

enum BOSS_STATE
{
	BOSS_STATE_STAND,
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
	void update(float dt) override;
	Boss();
	~Boss();
};

