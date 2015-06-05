#include "stdafx.h"
#include "Container.h"
#include <algorithm>

using namespace std;


Container::Container(int locX, int locY, int width, int height)
: ControlBaseExtended(locX, locY, width, height)
{
}

Container::~Container()
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		delete controlList[i];
	}
	controlList.clear();
}

void Container::AddControl(ControlBaseExtended* control)
{
	control->MovePosition(X, Y);
	controlList.push_back(control);
	
}

void Container::OnLoaded()
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnLoaded();
	}

	sort(controlList.begin(), controlList.end(), ControlBaseExtended::Compare);
}

void Container::OnPaint()
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnPaint();
	}
}

void Container::OnKeyboard(unsigned char key, int x, int y)
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnKeyboard(key, x, y);
	}
}

void Container::OnMouseDown(int button, int x, int y)
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnMouseDown(button, x, y);
	}
}

void Container::OnMouseUp(int button, int x, int y)
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnMouseUp(button, x, y);
	}
}

void Container::OnMouseMove(int button, int x, int y)
{
	for (size_t i = 0; i < controlList.size(); i++)
		{
			controlList[i]->OnMouseMove(button, x, y);
		}
}

void Container::OnResize(int width, int height)
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnResize(width,height);
	}
}

void Container::MovePosition(int dx, int dy)
{
	for (size_t i = 0; i < controlList.size(); i++)
	{
		controlList[i]->MovePosition(dx, dy);
	}
}

