#include "Tilemap.h"
#include<fstream>
using namespace std;

Tilemap* Tilemap::instance = 0;
void Tilemap::render(Camera* camera)
{
	int mapHeight = tileRows * tileHeight;

	int tileLeft, tileRight, tileTop, tileBottom;

	tileLeft = camera->getleft() / tileWidth;

	tileRight = camera->getRight() / tileWidth;

	tileTop = (mapHeight - camera->getTop()) / tileHeight;

	tileBottom = (mapHeight - camera->getBottom()) / tileHeight;

	if (tileLeft < 0)
	{
		tileLeft = 0;
	}

	if (tileTop < 0)
	{
		tileTop = 0;
	}

	if (tileRight >= tileColumns)
	{
		tileRight = tileColumns - 1;
	}

	if (tileBottom >= tileRows)
	{
		tileBottom = tileRows - 1;
	}

	for (size_t rowIndex = tileTop; rowIndex <= tileBottom; rowIndex++)
	{
		for (size_t columnIndex = tileLeft; columnIndex <= tileRight; columnIndex++)
		{
			int xWorldOfTile = columnIndex * tileWidth;
			int yWorldOfTile = mapHeight - rowIndex * tileHeight;


			float xViewOfTile = 0;
			float yViewOfTile = 0;

			camera->convertWorldToView(xWorldOfTile, yWorldOfTile, xViewOfTile, yViewOfTile);

			int tileValue = matrix[rowIndex][columnIndex];

			int xTileInTileSheet = tileWidth * (tileValue % tilesheetColumns);
			int yTileInTileSheet = tileHeight * (tileValue / tilesheetColumns);
			int widthTileInTilesheet = tileWidth;
			int heightTileInTilesheet = tileHeight;

			RECT rectCrop;
			SetRect(&rectCrop,
				xTileInTileSheet, 
				yTileInTileSheet,
				xTileInTileSheet + widthTileInTilesheet, 
				yTileInTileSheet + heightTileInTilesheet);

			tilesheet->Render(xViewOfTile, yViewOfTile, 0, 0, &rectCrop);
		}
	}
}

int Tilemap::getWorldHeight()
{
	return tileRows * tileHeight;
}

void Tilemap::Init(const char* tilesheetPath, const char* matrixPath)
{
	tilesheet = new GameTexture();
	tilesheet->Init(tilesheetPath);

	fstream fs(matrixPath);

	fs >> tileRows >> tileColumns >> tileWidth >> tileHeight >> tilesheetColumns;

	matrix = new int* [tileRows];

	for (size_t rowIndex = 0; rowIndex < tileRows; rowIndex++)
	{
		matrix[rowIndex] = new int[tileColumns];
		for (size_t columnIndex = 0; columnIndex < tileColumns; columnIndex++)
		{
			fs >> matrix[rowIndex][columnIndex];
		}
	}

}

void Tilemap::Init(const char* folderPath)
{
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");

	Init(tilesheetString.c_str(), matrixPathString.c_str());
}
Tilemap* Tilemap::getInstance()
{
	if (instance == 0)
		instance = new Tilemap();
	return instance;
}
Tilemap::Tilemap()
{
}
Tilemap::~Tilemap()
{
}
