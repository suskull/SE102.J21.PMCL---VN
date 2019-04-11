#pragma once
#include "PhysicsObject.h"
#include"KEY.h"

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
public:
	static Player* getInstance();

	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onUpdate(float dt) override;
	Player();
	~Player();
};

