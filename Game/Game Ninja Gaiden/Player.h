#pragma once
#include "PhysicsObject.h"
#include"KEY.h"
#include"Shuriken.h"
#include"Sword.h"
#include"WindmillShuriken.h"
#include"Flame.h"
#include"ScoreBar.h"

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
	PLAYER_ACTION_INJURED,
	PLAYER_ACTION_STAND_UNSTOPPABLE,
};

enum PLAYER_STATE {
	PLAYER_STATE_STAND,
	PLAYER_STATE_RUN,
	PLAYER_STATE_CLIMB,
	PLAYER_STATE_ATTACK,
	PLAYER_STATE_SUBWEAPON_NULL,
	PLAYER_STATE_SHURIKEN,
	PLAYER_STATE_WINDMILLSHURIKEN,
	PLAYER_STATE_SIT,
	PLAYER_STATE_SITATTACK,
	PLAYER_STATE_ROLL,
	PLAYER_STATE_ROLLATTACK,
	PLAYER_STATE_FLAME1,
	PLAYER_STATE_FLAME2,
	PLAYER_STATE_FLAME3,
	PLAYER_STATE_INJURED
};

enum PLAYER_SUBWEAPON {
	SUBWEAPON_NULL,
	SUBWEAPON_SHURIKEN,
	SUBWEAPON_FIREWHEEL,
	SUBWEAPON_WINDMILLSHURIKEN
};

class Player: 
	public PhysicsObject
{
	static Player* instance;
	PLAYER_STATE playerState;
	bool isAttacked;
	bool unstoppable;
	int currentSubWeapon;
public:
	static Player* getInstance();

	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	void onIntersect(MovableRect* other) override;
	void update(float dt) override;

	void setPlayerState(PLAYER_STATE playerState);
	PLAYER_STATE getPlayerState();
	void render(Camera* camera) override;

	bool getUnstoppable();
	void setUnstoppable(bool unstoppable);

	int getCurrentSubWeapon();
	void setCurrentSubWeapon(int currentSubWeapon);

	
	Player();
	~Player();
};

