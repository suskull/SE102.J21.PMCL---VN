#pragma once
#include "MovableRect.h"
#include"Sprite.h"
#include"GameTime.h"
#include"Camera.h"
#include"Tilemap.h"

class BaseObject :
	public MovableRect
{
	Sprite* sprite;

	int animationIndex, frameIndex;

	GameTime animationGameTime;

	bool isPause;
	
	bool isLastFrameAnimationDone;

	DIRECTION direction;

public:
	void setSprite(Sprite* sprite);
	Sprite* getSprite();

	int getAnimation();
	void setAnimation(int animation);

	int getFrameAnimation();
	void setFrameAnimation(int frameAnimation);

	bool getIsPause();
	virtual void setIsPause(bool isPause);

	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);

	DIRECTION getDirection();
	void setDirection(DIRECTION direction);

	virtual void onInitFromFile(ifstream& fs, int worldHeight);
	virtual void render(Camera* camera);

	virtual void onUpdate(float dt);

	virtual void update(float dt);

	float getWidthCurrentFrame();
	float getHeightCurrentFrame();

	BaseObject();
	~BaseObject();
};

