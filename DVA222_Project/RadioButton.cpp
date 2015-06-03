#include "stdafx.h"
#include "RadioButton.h"

RadioButton::RadioButton()
{

}

RadioButton::RadioButton(int locX, int locY, int width, int height)
:ToggleButton(locX, locY, width, height)
{
	delete image;
	image = new ImageBox(locX, locY, 10, 10);
	delete label;
	label = new Label("Radiobutton",locX + 10, locY);
	LoadBitmaps("RadioButtonNormal.bmp", "RadioButtonHover.bmp", "RadioButtonPressed.bmp");
	image->SetBitmap(normal);
}

void RadioButton::OnMouseMove(int button, int x, int y)
{
	if (x > X && x< X + 10 && y>Y && y < Y + 10)
	{
		mouseOver = true;
	}
	else
	{
		mouseOver = false;
	}
}