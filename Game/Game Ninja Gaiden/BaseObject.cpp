#include "BaseObject.h"

void BaseObject::setSprite(Sprite* sprite)
{
	this->sprite = sprite;
}

Sprite* BaseObject::getSprite()
{
	return this->sprite;
}

bool BaseObject::getIsPause()
{
	return isPause;
}

void BaseObject::setIsPause(bool isPause)
{
	this->isPause = isPause;
}

bool BaseObject::getIsLastFrameAnimationDone()
{
	return isLastFrameAnimationDone;
}

void BaseObject::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	this->isLastFrameAnimationDone = isLastFrameAnimationDone;
}

void BaseObject::onInitFromFile(ifstream& fs, int worldHeight)
{
	int collisionType, x, y, width, height;
	fs >> collisionType >> x >> y >> width >> height;
	set(x, worldHeight - y, width,  height);
	setCollisionType((COLLISION_TYPE)collisionType);
}

void BaseObject::update(float dt)
{
	if (!getIsPause())
	{
		goX();
		goY();
	}

	setIsLastFrameAnimationDone(false);

	if (!isPause && getSprite() != NULL)
	{
		if (animationGameTime.atTime())
		{
			sprite->update(animationIndex, frameIndex);
			if (frameIndex == 0)
			{
				setIsLastFrameAnimationDone(true);
			}
		}
	}

	if (!getAlive())
	{
		setIsRender(false);
	}

	onUpdate(dt);
}

float BaseObject::getWidthCurrentFrame()
{
	return this->getSprite()->animations[animationIndex]->frames[frameIndex]->right -
		this->getSprite()->animations[animationIndex]->frames[frameIndex]->left;
}

float BaseObject::getHeightCurrentFrame()
{
	return this->getSprite()->animations[animationIndex]->frames[frameIndex]->bottom -
		this->getSprite()->animations[animationIndex]->frames[frameIndex]->top;
}

void BaseObject::onUpdate(float dt)
{
	setIsPause(false);
}

void BaseObject::render(Camera* camera)
{
	if (getSprite() == 0 || !getIsRender() ||!getAlive())
		return;
	float xView, yView;
	camera->convertWorldToView(getX(), getY(), xView, yView);

	DIRECTION imageDirection = sprite->image->direction;

	DIRECTION currentDirection = getDirection();

	if (imageDirection != currentDirection)
	{
		int currentFrameWidth = getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->right -
			getSprite()->animations[getAnimation()]->frames[getFrameAnimation()]->left;
		D3DXMATRIX flipMatrix;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xView + currentFrameWidth / 2);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}

	sprite->render(xView, yView, animationIndex, frameIndex);

	if (direction != imageDirection)
	{
		D3DXMATRIX identityMatrix;
		D3DXMatrixIdentity(&identityMatrix);
		GameDirectX::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	}

	
}

int BaseObject::getAnimation()
{
	return animationIndex;
}

void BaseObject::setAnimation(int animation)
{
	if (this->animationIndex != animation)
	{
		setFrameAnimation(0);
		this->animationIndex = animation;
	}
	
}

int BaseObject::getFrameAnimation()
{
	return frameIndex;
}

void BaseObject::setFrameAnimation(int frameAnimation)
{
	this->frameIndex = frameAnimation;
}

DIRECTION BaseObject::getDirection()
{
	return direction;
}

void BaseObject::setDirection(DIRECTION direction)
{
	this->direction = direction;
}

BaseObject::BaseObject()
{
	
	setSprite(NULL);
	animationGameTime.init(GLOBALS_D("object_animation_time_default"));
	setDirection(DIRECTION_LEFT);
}


BaseObject::~BaseObject()
{
}
