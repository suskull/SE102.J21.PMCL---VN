#include "Animation.h"
int Animation::NextFrame(int currentFrame)
{
	if (currentFrame >= frames.size() - 1)
	{
		return 0;
	}
	return currentFrame + 1;
}
Animation::Animation()
{
}
Animation::~Animation()
{
}
