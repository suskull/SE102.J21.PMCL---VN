#include "BaseObject.h"


void BaseObject::update(float dt)
{
	
	/*setIsLastFrame(false);

	if (!pauseAnimation && getSprite() != NULL)
	{
		if (animationDelay->atTime())
		{
			sprite->update(actionIndex, actionFrameIndex);
			if (actionFrameIndex == 0)
			{
				sprite->update(actionIndex, actionFrameIndex);
				setIsLastFrame(true);
			}
		}
		
	}*/
}

void BaseObject::performUpdate(float dt)
{
	if (!isAlive())
		return;

	updateAnimation();

	//updateLocation();
	update(dt);
}

void BaseObject::render()
{
	sprite->render(getX(), getY(), actionIndex, actionFrameIndex);
	/*if (sprite == 0)
		return;
	if (!isAlive())
		return;
	if (!getRenderActive())
		return;
	int xV, yV;
	Camera::getInstance()->getWorldToViewLocation(getX(), getY(), xV, yV);
	xV -= (getCurrentFrameWidth() - getWidth()) / 2;
	yV -= (getCurrentFrameHeight() - getHeight()) / 2;

	if (direction != sprite->img->direction)
	{
		D3DXMATRIX flipMatrix;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xV + getCurrentFrameWidth() / 2);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}

	this->sprite->render(xV, yV, actionIndex, actionFrameIndex);
	if (direction != sprite->img->direction)
	{
		D3DXMATRIX identityMatrix;
		D3DXMatrixIdentity(&identityMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	}*/
}

void BaseObject::onLastFrameAnimation()
{
}


int BaseObject::distanceHorToFirstLocation()
{
	return abs(this->getMidX() - initBox->getMidX());
}


BaseObject::BaseObject()
{
	sprite = 0;
	actionIndex = 0;
	actionFrameIndex = 0;
	animationDelay = new GameTime();
	//setInterval(getGlobalValue("object_animation_interval"));
	setAlive(true);
	setRenderActive(true);
	setIsLastFrame(false);

}


BaseObject::~BaseObject()
{
}

Sprite* BaseObject::getSprite()
{
	return this->sprite;
}

void BaseObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}

int BaseObject::getAction()
{
	return actionIndex;
}

int BaseObject::getActionFrameIndex()
{
	return actionFrameIndex;
}

int BaseObject::getCurrentFrameWidth()
{
	//return getSprite()->getFrameWidth(actionIndex, actionFrameIndex);
	return 20;
}

int BaseObject::getCurrentFrameHeight()
{
	//return  getSprite()->getFrameHeight(actionIndex, actionFrameIndex);
	return 20;
}

void BaseObject::setAction(int actionIndex)
{
	if (this->actionIndex != actionIndex)
	{
		this->actionIndex = actionIndex;
		this->actionFrameIndex = 0;
	}
}

void BaseObject::setActionFrameIndex(int actionFrameIndex)
{
	this->actionFrameIndex = actionFrameIndex;
}

void BaseObject::updateAnimation()
{
	//if (sprite != 0)
	//{
	//	// truoc khi update frame
	//	int previousActionFrameIndex = actionFrameIndex;
	//	if (animationDelay->atTime())
	//	{
	//		this->sprite->update(actionIndex, actionFrameIndex);

	//	}
	//	setIsLastFrame(false);
	//	if (actionFrameIndex == 0 && previousActionFrameIndex == sprite->anims[getAction()].frameCount - 1)
	//	{
	//		setIsLastFrame(true);
	//		onLastFrameAnimation();
	//	}
	//}
}

void BaseObject::setRenderActive(bool renderActive)
{
	this->renderActive = renderActive;
}
bool BaseObject::getRenderActive()
{
	return this->renderActive;
}

void BaseObject::setInterval(int interval)
{
	this->animationDelay->init(interval);
}

int BaseObject::getInterval()
{
	return this->animationDelay->getTickPerFrame();
}

Rect* BaseObject::getInitBox()
{
	return initBox;
}

void BaseObject::setInitBox(Rect * initBox)
{
	this->initBox = initBox;
}

void BaseObject::restoreLocation()
{
	set(initBox->getX(), initBox->getY(), initBox->getWidth(), initBox->getHeight());
	setAlive(true);
}





void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::isPauseAnimation()
{
	return pauseAnimation;
}

bool BaseObject::isAlive()
{
	return alive;
}

void BaseObject::setAlive(bool alive)
{
	this->alive = alive;
}


bool BaseObject::getIsLastFrame()
{
	return this->isLastFrame;
}
void BaseObject::setIsLastFrame(bool isLastFrame)
{
	this->isLastFrame = isLastFrame;
}

bool BaseObject::canCollision()
{
	return isAlive();
}

bool BaseObject::canRemoveFromCamera()
{
	return true;
}


void BaseObject::onInit(fstream & fs, int worldHeight)
{
}

void BaseObject::setSpriteId(int spriteId)
{
	this->spriteId = spriteId;
	if (spriteId >= 0)
	{
		//sprite = SpriteManager::getInstance()->getSprites()[spriteId];
	}
}
