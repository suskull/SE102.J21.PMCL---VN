#pragma once
#include "AdditionalObject.h"
class ShotEffect :
	public AdditionalObject
{
public:
	void update(float dt) override;
	ShotEffect();
	~ShotEffect();
};

