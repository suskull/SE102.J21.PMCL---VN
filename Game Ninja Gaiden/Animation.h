#pragma once
#include"List.h"
#include"FrameAnimation.h"

class Animation
{
public:
	List<FrameAnimation*> frames;
	/* Chuyển sang frame kế khi truyền vào current frame */
	int NextFrame(int currentFrame);
	Animation();
	~Animation();
};

