#pragma once
#include"AdditionalObject.h"
#include"SpriteManager.h"
#include"Player.h"
class Flame :
	public Weapon
{
public:
	Flame();
	~Flame();
	void update(float dt) override;
	//void onIntersect(MovableRect* other) override;
};

