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
	void update();
	~GridTree();
};

