#pragma once


#include"GameDirectX.h"

enum DIRECTION
{
	DIRECTION_LEFT = -1,
	DIRECTION_RIGHT = 1
};



class GameTexture
{
private:
	LPDIRECT3DTEXTURE9 m_image;
public:

	int Width, Height;
	DIRECTION direction;

	GameTexture(const char* filepath, D3DCOLOR transColor = 0);

	void Init(const char* filepath, D3DCOLOR transColor = 0);
	GameTexture() {}

	DIRECTION getDirection();
	void setDirection(DIRECTION direction);
	void Render(int x, int y, int anchorX, int anchorY, RECT *r = 0);
	~GameTexture();
};
