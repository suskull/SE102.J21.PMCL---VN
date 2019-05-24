#pragma once
#include "AdditionalObject.h"

// hiệu ứng nhỏ khi SittingMan bắn
class ShotEffect :
	public AdditionalObject
{
public:
	void update(float dt) override;
	ShotEffect();
	~ShotEffect();
};

