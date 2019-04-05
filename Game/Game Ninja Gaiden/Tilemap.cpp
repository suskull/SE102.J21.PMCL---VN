#include "Tilemap.h"
#include<fstream>
using namespace std;

void Tilemap::render(Camera* camera)
{
	/* height của world */
	//int mapHeight = tileRows * tileHeight;

	/* tính các tile đang cắt camera */
	int tileLeft, tileRight, tileTop, tileBottom;

	/* tileLeft là vị trí cột camera cắt bên trái */
	tileLeft = camera->getleft() / tileWidth;

	/* tileRight là vị trí cột camera cắt bên phải */
	tileRight = camera->getRight() / tileWidth;

	/* tileTop là vị trí dòng camera cắt bên trên */
	tileTop = camera->getTop() / tileHeight;

	///* tileBottom là vị trí dòng camera cắt bên dưới */
	tileBottom = camera->getBottom() / tileHeight;

	if (tileLeft < 0)
	{
		tileLeft = 0;
	}

	if (tileTop < 0)
	{
		tileTop = 0;
	}

	if (tileRight > tileColumns)
	{
		tileRight = tileColumns - 1;
	}

	if (tileBottom > tileRows)
	{
		tileBottom = tileRows - 1;
	}

	for (size_t rowIndex = tileTop; rowIndex < tileBottom; rowIndex++)
	{
		for (size_t columnIndex = tileLeft; columnIndex <= tileRight; columnIndex++)
		{
			int xWorldOfTile = columnIndex * tileWidth;
			int yWorldOfTile = rowIndex * tileHeight;

			/* tính vị trí view của tile */

			float xViewOfTile = 0;
			float yViewOfTile = 0;

			camera->convertWorldToView(xWorldOfTile, yWorldOfTile, xViewOfTile, yViewOfTile);

			/* tìm hình chữ nhật là vị trí của tile trong tilesheet */
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
Tilemap::Tilemap()
{
}
Tilemap::~Tilemap()
{
}
