#pragma once
#include "stdafx.h"
#include "Graphix.h"
#include <vector>

using namespace std;

class Container : public ControlBase
{
protected:
	vector<ControlBase*> controlList; // The order of the elements in this list represents the Z value. The last added control will be in front.
public:
	Container();
	Container(int locX, int locY, int width, int height);
	~Container();

	void AddControl(ControlBase *control);
};