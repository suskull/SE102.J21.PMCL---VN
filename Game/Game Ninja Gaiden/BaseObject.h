#pragma once
#include "MovableRect.h"
#include"Sprite.h"
#include"GameTime.h"
#include"Camera.h"

class BaseObject :
	public MovableRect
{
	Sprite* sprite;

	int animationIndex, frameIndex;

	GameTime animationGameTime;

	bool pauseAnimation;
	
	bool isLastFrameAnimationDone;

	DIRECTION direction;

public:
	void setSprite(Sprite* sprite);
	Sprite* getSprite();

	int getAnimation();
	void setAnimation(int animation);

	int getFrameAnimation();
	void setFrameAnimation(int frameAnimation);

	bool getPauseAnimation();
	virtual void setPauseAnimation(bool pauseAnimation);

	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);

	DIRECTION getDirection();
	void setDirection(DIRECTION direction);

	virtual void onInitFromFile(ifstream& fs);
	virtual void render(Camera* camera);

	virtual void onUpdate(float dt);

	void update(float dt);

	BaseObject();
	~BaseObject();
};

