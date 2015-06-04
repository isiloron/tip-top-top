#include "stdafx.h"
#include "RadioButton.h"


RadioButton::RadioButton(int locX, int locY, int width, int height)
:ToggleButton(locX, locY, width, height)
{
	delete label;
	label = new Label("Radiobutton", locX + width+ 4, locY+(height/2)+5);

	LoadBitmaps("RadioButtonNormal.bmp", "RadioButtonHover.bmp", "RadioButtonPressed.bmp");
}