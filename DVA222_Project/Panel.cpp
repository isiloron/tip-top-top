#include "stdafx.h"
#include "Graphix.h"
#include "Panel.h"

using namespace std;

Panel::Panel(int locX, int locY, int width, int height)
	: Container(locX, locY, width, height)
{
	backgroundColor = Color(255,255,255); // white default
}

void Panel::SetBackgroundColor(int r, int g, int b)
{
	backgroundColor.SetRGB(r, g, b);
}

void Panel::OnPaint(void)
{
	backgroundColor.DrawWith();
	FillRectangle(X, Y, Width, Height);

	Container::OnPaint();
}

void Panel::MovePosition(int dx, int dy)
{
	ControlBaseExtended::MovePosition(dx, dy);
	Container::MovePosition(dx, dy);
}