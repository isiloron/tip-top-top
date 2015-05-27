#include "stdafx.h"
#include "Graphix.h"
#include "Panel.h"

using namespace std;

Panel::Panel()
{
	r = g = b = 255;
}

Panel::Panel(int locX, int locY, int width, int height)
	: Container(locX, locY, width, height)
{
	r = g = b = 255;
}

Panel::~Panel()
{

}

void Panel::SetBackgroundColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Panel::OnPaint(void)
{
	SetColor(r, g, b);
	DrawRectangle(X, Y, Width, Height);

	for (int i = 0; i < controlList.size(); i++)
	{
		controlList[i]->OnPaint();
	}
}
