#pragma once
#include"Animation.h"
#include"GameTexture.h"
#include"GameUtils.h"
class Sprite
{
public:
	GameTexture* image;
	List<Animation*> animations;

	void InitFromFile(const char* imagePath, const char* infoPath);

	void update(int animationIndex,int& frameIndex);

	void render(int x,int y, int animationIndex, int frameIndex);

	Sprite();
	~Sprite();
};

