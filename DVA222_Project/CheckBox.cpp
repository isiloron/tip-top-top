#include "stdafx.h"
#include "CheckBox.h"

CheckBox::CheckBox()
{

}

CheckBox::CheckBox(int locX, int locY, int width, int height)
	:ToggleButton(locX,locY,width,height)
{
	delete normal;
	normal = new ImageBox(locX, locY, 10, 10);
	delete hover;
	hover = new ImageBox(locX, locY, 10, 10);
	delete press;
	press = new ImageBox(locX, locY, 10, 10);

	delete label;
	label = new Label("Checkbox",locX + 10, locY);

	LoadBitmaps("CheckBoxNormal.bmp", "CheckBoxHover.bmp", "CheckBoxPressed.bmp");

	image=normal;
}

void CheckBox::OnMouseMove(int button, int x, int y)
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