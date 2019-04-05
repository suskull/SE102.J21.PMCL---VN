#pragma once
#include"GameTexture.h"
#include"Camera.h"

class Tilemap
{
	int tileWidth;
	int tileHeight;

	int tileRows;
	int tileColumns;

	int tilesheetColumns;

	GameTexture* tilesheet;

	int** matrix;
public:

	void render(Camera* camera);

	int getWorldHeight();

	void Init(const char* tilesheetPath, const char* matrixPath);
	void Init(const char* folderPath);

	Tilemap();
	~Tilemap();
};

