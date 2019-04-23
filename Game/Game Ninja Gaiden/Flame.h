#pragma once
#include"AdditionalObject.h"
#include"SpriteManager.h"
#include"Player.h"
class Flame :
	public AdditionalObject
{
public:
	Flame();
	~Flame();
	void update(float dt) override;
	//void onIntersect(MovableRect* other) override;
};

