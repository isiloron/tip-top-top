#include "stdafx.h"
#include "CheckBox.h"



CheckBox::CheckBox(int locX, int locY, int width, int height)
	:ToggleButton(locX,locY,width,height)
{
	delete label;
	label = new Label("Checkbox", locX + width + 4, locY + (height / 2) + 5);

	LoadBitmaps("CheckBoxNormal.bmp", "CheckBoxHover.bmp", "CheckBoxPressed.bmp");
}