#pragma once
#include"List.h"
#include"FrameAnimation.h"

class Animation
{
public:
	List<FrameAnimation*> frames;
	int NextFrame(int currentFrame);
	Animation();
	~Animation();
};

