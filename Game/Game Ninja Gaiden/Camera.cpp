#include "Camera.h"
#include<d3dx9.h>
#include"Player.h"

Camera* Camera::instance = 0;
Camera* Camera::getInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::convertWorldToView(float xWorld, float yWorld, float& xView, float& yView)
{
	xView = xWorld - this->getX();
	yView = yWorld - this->getY();
}

void Camera::update()
{
	setDx(0);

	Player* player = Player::getInstance();
	if (player->getDx() < 0 && getMidX() > player->getMidX())
	{
		setDx(player->getDx());
	}
	if (player->getDx() > 0 && getMidX() < player->getMidX())
	{
		setDx(player->getDx());
	}
	goX();
	goY();
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
