#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
#include"Player.h"

enum PANTHER_STATE
{
	PATHER_STATE_WAIT,
	PATHER_STATE_RUN
};

class Panther
	: public Enemy
{
	PANTHER_STATE pantherState;
public:
	float vx = GLOBALS_D("panther_vx");
	float score = GLOBALS_D("panther_score");
	void update(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;

	void setPantherState(PANTHER_STATE pantherState);
	Panther();
	~Panther();
};

