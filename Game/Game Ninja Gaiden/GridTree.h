#pragma once
#include "Camera.h"
#include <string>
using namespace std;
#include <vector>
#include"GridNode.h"
#include"Camera.h"

class GridTree
{
	static GridTree* instance;
	vector<GridNode> listNodes;
public:
	static GridTree* getInstance();
	GridTree();
	void initGridTree(string path, int worldHeight);
	void update(List<BaseObject*> allObjects, List<BaseObject*> &objectsInCamera);
	~GridTree();
	void addListObjects(GridNode gridNode, List<BaseObject*> allObjects, List<BaseObject*>& objectsInCamera);
	void removeListObjects(GridNode gridNode, List<BaseObject*> allObjects, List<BaseObject*>& objectsInCamera);
	void resetLocationAndStateOfObjects(GridNode gridNode, List<BaseObject*> allObjects);
};

