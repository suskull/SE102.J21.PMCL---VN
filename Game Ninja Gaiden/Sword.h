#pragma once
#include "PhysicsObject.h"
#include "ExplosionEffect.h"
#include"Weapon.h"
class Sword 
	: public Weapon
{
public:
	Sword();
	~Sword();
	void update(float dt) override;
	void render(Camera* camera) override;
	void onIntersect(MovableRect* other) override;
		
};

