#include "Grid.h"
#include <fstream>
#include "GridNode.h"
#include "Collision.h"
using namespace std;

Grid* Grid::instance = 0;
Grid* Grid::getInstance()
{
	if (instance == 0)
		instance = new Grid();
	return instance;
}
Grid::Grid()
{
}

void Grid::initGrid(string pathGrid, int worldHeight)
{
	int countGridNode;
	fstream fs(pathGrid);
	fs >> countGridNode;
	for (size_t i = 0; i < countGridNode; i++)
	{
		GridNode node;

		fs >> node.Id >>node.X >> node.Y >> node.numberofObjects;

		//chuyển ngược trục tọa độ theo chiều Y.
		node.Y = worldHeight - node.Y;
		
		node.rect.set(node.X, node.Y, GLOBALS_D("backbuffer_width") / 2, GLOBALS_D("backbuffer_height") / 2);

		if (node.numberofObjects == 0)
		{
			listNodes.push_back(node);
			continue;
		}
		for (size_t j = 0; j < node.numberofObjects; j++)
		{
			int idObject;
			fs >> idObject;
			node.listObjects.push_back(idObject);
		}

		listNodes.push_back(node);
	}
}

void Grid::update(List<BaseObject*> allObjects, List<BaseObject*> &objectsInCamera)
{
	//xét bouding rect của từng node với camera
	for (size_t i = 0; i < listNodes.size(); i++)
	{
		//Nếu intersect thì thêm tất cả object trong node vào list ObjectInCamera
		bool IsIntersect = Collision::AABBCheck(&listNodes[i].rect, Camera::getInstance());
		if (IsIntersect)
		{
			addListObjects(listNodes[i], allObjects, objectsInCamera);
			listNodes[i].isIntesected = true;
		}
		else if (listNodes[i].isIntesected) 
		{
			resetLocationAndStateOfObjects(listNodes[i], allObjects);
			removeListObjects(listNodes[i], allObjects, objectsInCamera);
			listNodes[i].isIntesected = false;
		}
			
	}
}




Grid::~Grid()
{
}

void Grid::addListObjects(GridNode gridNode, List<BaseObject*> allObjects, List<BaseObject*>& objectsInCamera)
{
	for (size_t j = 0; j < gridNode.listObjects.size(); j++)
	{
		auto idObject = gridNode.listObjects[j];

		objectsInCamera._Add(allObjects.at(idObject));
	}
}

void Grid::removeListObjects(GridNode gridNode, List<BaseObject*> allObjects, List<BaseObject*>& objectsInCamera)
{
	for (size_t j = 0; j < gridNode.listObjects.size(); j++)
	{
		auto idObject = gridNode.listObjects[j];

		objectsInCamera._Remove(allObjects.at(idObject));
	}
}

void Grid::resetLocationAndStateOfObjects(GridNode gridNode, List<BaseObject*> allObjects)
{
	for (size_t j = 0; j < gridNode.listObjects.size(); j++)
	{
		auto idObject = gridNode.listObjects[j];
		allObjects.at(idObject)->ResetLocation();
		allObjects.at(idObject)->setAlive(true);
		if(allObjects.at(idObject)->getCollisionType() == COLLISION_TYPE_ENEMY)
			allObjects.at(idObject)->setIsRender(true);
	}
}

void Grid::resetListNodes()
{
	listNodes.clear();
}
