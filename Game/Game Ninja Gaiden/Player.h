#pragma once
#include "PhysicsObject.h"
#include"KEY.h"
#include"Shuriken.h"

enum PLAYER_ACTION {
	PLAYER_ACTION_STAND,
	PLAYER_ACTION_RUN,
	PLAYER_ACTION_CLIMB,
	PLAYER_ACTION_ATTACK,
	PLAYER_ACTION_SHURIKEN,
	PLAYER_ACTION_SIT,
	PLAYER_ACTION_SITATTACK,
	PLAYER_ACTION_ROLL,
	PLAYER_ACTION_ROLLATTACK,
};

enum PLAYER_STATE {
	PLAYER_STATE_STAND,
	PLAYER_STATE_RUN,
	PLAYER_STATE_CLIMB,
	PLAYER_STATE_ATTACK,
	PLAYER_STATE_SHURIKEN,
	PLAYER_STATE_SIT,
	PLAYER_STATE_SITATTACK,
	PLAYER_STATE_ROLL,
	PLAYER_STATE_ROLLATTACK,
};

class Player: 
	public PhysicsObject
{
	static Player* instance;
	PLAYER_STATE playerState;
public:
	static Player* getInstance();

	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void update(float dt) override;

	void setPlayerState(PLAYER_STATE playerState);
	Player();
	~Player();
};

