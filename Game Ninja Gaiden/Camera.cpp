#include "Camera.h"
#include<d3dx9.h>
#include"Player.h"
#include"MapManager.h"

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
	/*World to View */
	D3DXMATRIX matrixWorldToView;
	D3DXMatrixIdentity(&matrixWorldToView);
	matrixWorldToView._22 = -1;
	matrixWorldToView._41 = -this->getX();
	matrixWorldToView._42 = this->getY();

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

	//ràng buộc player k vẽ ra ngoài bên trái và phải map
	if (player->getX() < 0)
	{
		player->setX(0);
	}

	int widthCurrentMap = MapManager::getInstance()->getCurrentMap()->width;

	if (player->getX() > widthCurrentMap - player->getWidth())
		player->setX(widthCurrentMap - player->getWidth());
	
	//ràng buộc camera k vẽ ngoài bên trái và phải map
	if (getX() + getDx() < 0  && getDx() < 0)
	{
		setX(0);
		setDx(0);
	}

	if (getRight() + getDx() > widthCurrentMap && getDx() > 0)
	{
		setX(widthCurrentMap - getWidth());
		setDx(0);
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
