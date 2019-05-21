#pragma once
#include "AdditionalObject.h"
class BossEffect :
	public AdditionalObject
{
public:
	void update(float dt) override;
	void render(Camera* camera) override;
	BossEffect();
	~BossEffect();
};

