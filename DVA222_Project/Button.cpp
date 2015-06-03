#include "stdafx.h"
#include "Button.h"

using namespace std;


Button::Button(int locX, int locY, int width, int height)
	: ControlBase(locX, locY, width, height)
{
	normal = new ImageBox(locX, locY, width, height);
	hover = new ImageBox(locX, locY, width, height);
	press = new ImageBox(locX, locY, width, height);
	image = normal;
	label = new Label("Button",locX, locY);
	mouseOver = pressed = false;
}

Button::~Button()
{
	delete normal;
	delete hover;
	delete press;
	delete image;
	delete label;
}

void Button::LoadBitmaps(string normal, string hover, string press)
{
	LoadNormalBitmap(normal);
	LoadHoverBitmap(hover);
	LoadPressBitmap(press);
}

void Button::LoadNormalBitmap(string filename)
{
	if (normal != NULL)
		normal->SetTexture(filename);
}

void Button::LoadHoverBitmap(string filename)
{
	if (hover != NULL)
		hover->SetTexture(filename);
}

void Button::LoadPressBitmap(string filename)
{
	if (press != NULL)
		press->SetTexture(filename);
}

void Button::SetLabel(string text)
{
	if (label != NULL)
		label->SetLabel(text);
}

void Button::OnLoaded()
{
	if (normal != NULL)
		normal->OnLoaded();
	if (hover != NULL)
		hover->OnLoaded();
	if (press != NULL)
		press->OnLoaded();
	if (label != NULL)
		label->OnLoaded();
}

void Button::OnPaint()
{
	if (pressed)
	{
		image = press;
	}
	else if (mouseOver)
	{
		image = hover;
	}
	else
	{
		image = normal;
	}
	image->OnPaint();

	if (label != NULL)
		label->OnPaint();
}

void Button::OnMouseDown(int button, int x, int y)
{
	if (mouseOver)
	{
		pressed = true;
	}
}

void Button::OnMouseUp(int button, int x, int y)
{
	pressed = false;
}

void Button::OnMouseMove(int button, int x, int y)
{
	if (x > X && x<X + Width && y>Y && y < Y + Height)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = pressed = false;
	}
}

void Button::UpdatePosition(int dx, int dy)
{
	ControlBase::UpdatePosition(dx, dy);
	normal->UpdatePosition(dx, dy);
	hover->UpdatePosition(dx, dy);
	press->UpdatePosition(dx, dy);
	label->UpdatePosition(dx, dy);
}