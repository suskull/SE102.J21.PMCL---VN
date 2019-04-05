#pragma once
#include "MovableRect.h"
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a
#include<iostream>
using namespace std;

class Collision
{
public:
	static MovableRect* GetSweptBroadPhaseBox(MovableRect* box);
	static bool AABBCheck(Rect* M, Rect* S);
	static float SweptAABB(MovableRect* M, MovableRect* S, float& normalX, float& normalY);
	static void CheckCollision(MovableRect* M, MovableRect* S);

	Collision();
	~Collision();
};
