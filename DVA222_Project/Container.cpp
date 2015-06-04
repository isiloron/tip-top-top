#include "stdafx.h"
#include "Graphix.h"
#include "Container.h"

using namespace std;


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

void Container::OnLoaded()
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnLoaded();
	}
}

void Container::OnPaint()
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnPaint();
	}
}

void Container::OnKeyboard(unsigned char key, int x, int y)
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnKeyboard(key, x, y);
	}
}

void Container::OnMouseDown(int button, int x, int y)
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnMouseDown(button, x, y);
	}
}

void Container::OnMouseUp(int button, int x, int y)
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnMouseUp(button, x, y);
	}
}

void Container::OnMouseMove(int button, int x, int y)
{
	if (x>X && x<X + Width && y>Y && y < Y + Height)
	{
		for (int i = 0; i < controlList.size(); i++)
		{
			controlList[i]->OnMouseMove(button, x, y);
		}
	}
}

void Container::OnResize(int width, int height)
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnResize(width,height);
	}
}

void Container::MovePosition(int dx, int dy)
{
	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->MovePosition(dx, dy);
	}
}

