//#include "Camera.h"
//#include"GameDirectX.h"
//
//Camera::Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors)
//{
//	this->width = width;
//	this->height = height;
//	this->angle = angle;
//	this->scaleFactors = scaleFactors;
//
//	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
//	D3DXMatrixIdentity(&identityMatrix);
//}
//
//Camera::~Camera()
//{
//
//}
//
//void Camera::Update(Player* player)
//{
//	float cameraX = this->width / 2, cameraY = this->height / 2;
//	if (player)
//	{
//		cameraX = player->getX();
//		cameraY = player->getY();
//	}
//
//	this->viewMatrix = D3DXMATRIX(
//		scaleFactors.x * cos(angle), scaleFactors.x * sin(angle), 0, 0,
//		-scaleFactors.y * sin(angle), scaleFactors.y * cos(angle), 0, 0,
//		0, 0, scaleFactors.z, 0,
//		-cameraX * scaleFactors.x * cos(angle) + cameraY * scaleFactors.y * sin(angle), -cameraX * scaleFactors.y * sin(angle) - cameraY * scaleFactors.y * cos(angle), 0, 1
//	);
//}
//
////void Camera::Follow(Player* player)
////{
////	this->player = player;
////}
////
////void Camera::Unfollow()
////{
////	this->player = nullptr;
////}
////
////bool Camera::IsFollowing() const
////{
////	return this->following != nullptr;
////}
//
//void Camera::SetTransform(GraphicsDevice* gDevice) const
//{
//	GameDirectX::getInstance()->GetDevice()->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
//	GameDirectX::getInstance()->GetDevice()->SetTransform(D3DTS_WORLD, &identityMatrix);
//	GameDirectX::getInstance()->GetDevice()->SetTransform(D3DTS_VIEW, &viewMatrix);
//}
//
//
//
//
//
//
