#include "stdafx.h"
#include "CheckBox.h"

CheckBox::CheckBox()
{

}

CheckBox::CheckBox(int locX, int locY, int width, int height)
	:ToggleButton(locX,locY,width,height)
{
	delete image;
	image = new ImageBox(locX, locY, 10, 10);
	delete label;
	label = new Label(locX + 10, locY, width - 10, height);
	LoadBitmaps("CheckBoxNormal.bmp", "CheckBoxHover.bmp", "CheckBoxPressed.bmp");
	image->SetBitmap(normal);
	label->SetLabel("Checkbox");
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