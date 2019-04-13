#pragma once
#include "PhysicsObject.h"
class Sword 
	: public PhysicsObject
{
	static Sword* instance;
public:
	static Sword* getInstance();
	Sword();
	~Sword();
	void update(float dt);
	void render(Camera* camera) override;
};

