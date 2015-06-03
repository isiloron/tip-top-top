#include "stdafx.h"
#include "CheckBox.h"



CheckBox::CheckBox(int locX, int locY, int width, int height)
	:ToggleButton(locX,locY,width,height)
{
	delete normal;
	normal = new ImageBox(locX, locY, 12, 12);
	delete hover;
	hover = new ImageBox(locX, locY, 12, 12);
	delete press;
	press = new ImageBox(locX, locY, 12, 12);

	delete label;
	label = new Label("Checkbox", locX + 16, locY + 10);

	LoadBitmaps("CheckBoxNormal.bmp", "CheckBoxHover.bmp", "CheckBoxPressed.bmp");

	image=normal;
}

void CheckBox::OnMouseMove(int button, int x, int y)
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