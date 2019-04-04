#pragma once
#include "PhysicsBox.h"
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a
#include<iostream>
using namespace std;

class Collision
{
public:
	static PhysicsBox* GetSweptBroadPhaseBox(PhysicsBox* box);
	static bool AABBCheck(Rect* M, Rect* S);
	static float SweptAABB(PhysicsBox* M, PhysicsBox* S, float& normalX, float& normalY);
	static void CheckCollision(PhysicsBox* M, PhysicsBox* S);

	Collision();
	~Collision();
};
