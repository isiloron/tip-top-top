#include "stdafx.h"
#include "Graphix.h"
#include "Container.h"

using namespace std;

Container::Container()
{
}

Container::Container(int locX, int locY, int width, int height)
	: ControlBase(locX, locY, width, height)
{
}

Container::~Container()
{
	for (int i = 0; i < controlList.size(); i++)
	{
		delete controlList[i];
	}
	controlList.clear();
}

void Container::AddControl(ControlBase* control)
{
	controlList.push_back(control);
}