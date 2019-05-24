#pragma once
#include "Enemy.h"
#include"Player.h"
#include"WeaponSittingMan.h"
#include"ShotEffect.h"

enum SITTINGMAN_STATE
{
	SITTINGMAN_STATE_WAIT,
	SITTINGMAN_STATE_ATTACK
};

enum SITTINGMAN_ACTION
{
	SITTINGMAN_ACTION_WAIT,
	SITTINGMAN_ACTION_ATTACK
};

class SittingMan :
	public Enemy
{
	SITTINGMAN_STATE sittingManState;
	bool isAttacking;
	int count;
public:
	void setSittingManState(SITTINGMAN_STATE sittingManState);
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	SittingMan();
	~SittingMan();
};

