#pragma once
#include "BaseObject.h"
#include <vector>
#include <string>
using namespace std;

class GridNode
{
public:
	string Id;
	int X;
	int Y;
	int numberofObjects;
	vector<int> listObjects;
	Rect rect;
	bool isIntesected;
public:
	GridNode();
	~GridNode();
};

