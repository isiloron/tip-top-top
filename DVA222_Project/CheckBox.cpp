#include "stdafx.h"
#include "CheckBox.h"

CheckBox::CheckBox()
{
	SetBitmaps("", "", "");
}

CheckBox::CheckBox(int locX, int locY, int width, int height)
	: ToggleButton(locX,locY,width,height)
{

}