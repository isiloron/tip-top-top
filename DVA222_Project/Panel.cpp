#include "stdafx.h"
#include "Graphix.h"
#include "Panel.h"

using namespace std;

Panel::Panel(int locX, int locY, int width, int height)
	: Container(locX, locY, width, height)
{
	r = g = b = 255;
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
	FillRectangle(X, Y, Width, Height);

	Container::OnPaint();
}

void Panel::MovePosition(int dx, int dy)
{
	ControlBaseExtended::MovePosition(dx, dy);
	Container::MovePosition(dx, dy);
}