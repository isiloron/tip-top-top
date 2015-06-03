#include "stdafx.h"
#include "Graphix.h"
#include "Panel.h"

using namespace std;

Panel::Panel()
{
}

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

void Panel::UpdatePosition(int dx, int dy)
{
	X += dx;
	Y += dy;
	Container::UpdatePosition(dx, dy);
}