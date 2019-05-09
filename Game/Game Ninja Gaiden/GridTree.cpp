#include "GridTree.h"
#include <fstream>
#include "GridNode.h"
#include "Collision.h"
using namespace std;

GridTree* GridTree::instance = 0;
GridTree* GridTree::getInstance()
{
	if (instance == 0)
		instance = new GridTree();
	return instance;
}
GridTree::GridTree()
{
}

void GridTree::initGridTree(string pathGridTree, int worldHeight)
{
	int countGridNode;
	fstream fs(pathGridTree);
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

void GridTree::update()
{
	//xét bouding rect của từng node với camera
	for (size_t i = 0; i < listNodes.size(); i++)
	{
		bool IsIntersect = Collision::AABBCheck(&listNodes[i].rect, Camera::getInstance());
		if (IsIntersect)
		{
			int a = 0;
		}
		
	}
}




GridTree::~GridTree()
{
}
