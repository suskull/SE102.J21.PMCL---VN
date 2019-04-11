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
	/* Hướng mặc định của texture */
	DIRECTION direction;

	GameTexture(const char* filepath, D3DCOLOR transColor = 0);

	/** Tạo texture
	filepath: duong dan file hinh anh
	transColor: mau can trong suot
	*/
	void Init(const char* filepath, D3DCOLOR transColor = 0);
	GameTexture() {}

	/** Vẽ texture
	x,y: vị trí bức hình trong backbuffer
	r: vùng chữ nhật cần vẽ
	anchorX : điểm neo x
	anchorY : điểm neo y
	*/
	DIRECTION getDirection();
	void setDirection(DIRECTION direction);
	void Render(int x, int y, int anchorX, int anchorY, RECT *r = 0);
	~GameTexture();
};
