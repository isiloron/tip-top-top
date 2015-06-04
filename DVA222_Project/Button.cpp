#include "stdafx.h"
#include "Button.h"

using namespace std;


Button::Button(int locX, int locY, int width, int height)
	: ControlBaseExtended(locX, locY, width, height)
{
	normal = new ImageBox(locX, locY, width, height);
	hover = new ImageBox(locX, locY, width, height);
	press = new ImageBox(locX, locY, width, height);
	image = normal;
	label = new Label("Button",locX, locY + height/2);
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
	normal->SetTexture(filename);
}

void Button::LoadHoverBitmap(string filename)
{
	hover->SetTexture(filename);
}

void Button::LoadPressBitmap(string filename)
{
	press->SetTexture(filename);
}

void Button::SetLabel(string text)
{
	label->SetLabel(text);
}

void Button::SetLabelColor(int r, int g, int b)
{
	label->SetLabelColor(r,g,b);
}

void Button::OnLoaded()
{
	normal->OnLoaded();
	hover->OnLoaded();
	press->OnLoaded();
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

void Button::MovePosition(int dx, int dy)
{
	ControlBaseExtended::MovePosition(dx, dy);
	normal->MovePosition(dx, dy);
	hover->MovePosition(dx, dy);
	press->MovePosition(dx, dy);
	label->MovePosition(dx, dy);
}