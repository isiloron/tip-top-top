#include "stdafx.h"
#include "Button.h"

using namespace std;

Button::Button()
{

}

Button::Button(int locX, int locY, int width, int height)
	: ControlBase(locX, locY, width, height)
{
	normal = new ImageBox(locX, locY, width, height);
	hover = new ImageBox(locX, locY, width, height);
	press = NULL;
	image = new ImageBox(locX, locY, width, height);
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
	delete normal;
	normal = new Bitmap(filename);
}

void Button::LoadHoverBitmap(string filename)
{
	delete hover;
	hover = new Bitmap(filename);
}

void Button::LoadPressBitmap(string filename)
{
	delete press;
	press = new Bitmap(filename);
}

void Button::SetLabel(string text)
{
	if (label != NULL)
		label->SetLabel(text);
}

void Button::OnLoaded()
{
	if (image != NULL)
		image->OnLoaded();
	if (label != NULL)
		label->OnLoaded();
}

void Button::OnPaint()
{
	if (image != NULL)
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
	}
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
	if (x > X && x<X + Width && y>Y && y > Y + Height)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = pressed = false;
	}
}