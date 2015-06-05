#include "StdAfx.h"
#include "Graphix.h"
#include "CheckBoxGroup.h"

using namespace std;

CheckBoxGroup::CheckBoxGroup(string initTitle,int x,int y,int w,int h):ToggleButtonGroup(initTitle,x,y,w,h)
{
}

void CheckBoxGroup::AddToggleButton(string buttonLabel)
{
	CheckBox* newbox = new CheckBox(12,13*numberOfButtons,12,12);
	newbox->SetLabel(buttonLabel);
	AddControl(newbox);
	numberOfButtons++;
}
