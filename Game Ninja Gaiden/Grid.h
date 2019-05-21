#pragma once
#include "Camera.h"
#include <string>
using namespace std;
#include <vector>
#include"GridNode.h"
#include"Camera.h"

class Grid
{
	static Grid* instance;
	vector<GridNode> listNodes;
public:
	static Grid* getInstance();
	Grid();
	void initGrid(string path, int worldHeight);
	void update(List<BaseObject*> allObjects, List<BaseObject*> &objectsInCamera);
	~Grid();
	void addListObjects(GridNode gridNode, List<BaseObject*> allObjects, List<BaseObject*>& objectsInCamera);
	void removeListObjects(GridNode gridNode, List<BaseObject*> allObjects, List<BaseObject*>& objectsInCamera);
	void resetLocationAndStateOfObjects(GridNode gridNode, List<BaseObject*> allObjects);
	void resetListNodes();
};

