#include "stdafx.h"
#include "Button.h"

using namespace std;

Button::Button()
{
	normal = hover = press = NULL;
	image = new ImageBox();
	label = new Label();
	mouseOver = pressed = false;
}

Button::Button(int locX, int locY, int width, int height)
	: ControlBase(locX, locY, width, height)
{
	normal = hover = press = NULL;
	image = new ImageBox(locX, locY, width, height);
	label = new Label(locX, locY, width, height);
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

void Button::SetBitmaps(string normal, string hover, string press)
{
	SetNormalBitmap(normal);
	SetHoverBitmap(hover);
	SetPressBitmap(press);
}

void Button::SetNormalBitmap(string filename)
{
	delete normal;
	normal = new Bitmap(filename);
}

void Button::SetHoverBitmap(string filename)
{
	delete hover;
	hover = new Bitmap(filename);
}

void Button::SetPressBitmap(string filename)
{
	delete press;
	press = new Bitmap(filename);
}

void Button::OnLoaded()
{
	image->OnLoaded();
	label->OnLoaded();
}

void Button::OnPaint()
{
	if (pressed)
	{
		image->SetBitmap(press);
	}
	else if (mouseOver)
	{
		image->SetBitmap(hover);
	}
	else
	{
		image->SetBitmap(normal);
	}

	image->OnPaint();
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
	if (x > X && x<X + Width && y>Y && y > Y + Height)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = pressed = false;
	}
}