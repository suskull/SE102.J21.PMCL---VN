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
	/* ma trận biến đổi world to view */
	D3DXMATRIX matrixWorldToView;
	D3DXMatrixIdentity(&matrixWorldToView);
	matrixWorldToView._22 = -1;
	matrixWorldToView._41 = -this->getX();
	matrixWorldToView._42 = this->getY();

	/* nhân ma trận đó với xWorld yWorld ta được xView yView */
	D3DXVECTOR3 pos3(xWorld, yWorld, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrixWorldToView);

	xView = MatrixResult.x;
	yView = MatrixResult.y;
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
