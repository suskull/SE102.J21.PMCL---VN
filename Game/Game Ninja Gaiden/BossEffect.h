#pragma once
#include "AdditionalObject.h"
class BossEffect:
	public AdditionalObject
{
public:
	void update(float dt) override;
	
	BossEffect();
	~BossEffect();
};

