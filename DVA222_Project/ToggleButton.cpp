#include "stdafx.h"
#include "ToggleButton.h"


ToggleButton::ToggleButton(int locX, int locY, int width, int height)
: Button(locX, locY, width, height)
{

}

void ToggleButton::OnMouseDown(int button, int x, int y)
{
	if (mouseOver)
	{
		pressed = !pressed ? true : false;
	}
}

void ToggleButton::OnMouseMove(int button, int x, int y)
{
	if (x > X && x< X + 12 && y>Y && y < Y + 12)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = false;
	}
}

void ToggleButton::OnMouseUp(int button, int x, int y)
{

}