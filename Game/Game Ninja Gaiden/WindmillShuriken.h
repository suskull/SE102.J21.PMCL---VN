#pragma once
#include"AdditionalObject.h"
#include"SpriteManager.h"
#include"Player.h"
class WindmillShuriken:
	public AdditionalObject
{
public:
	WindmillShuriken();
	~WindmillShuriken();
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
};

