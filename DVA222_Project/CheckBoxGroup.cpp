#include "StdAfx.h"
#include "Graphix.h"
#include "CheckBoxGroup.h"

using namespace std;

CheckBoxGroup::CheckBoxGroup(string initTitle,int x,int y,int w,int h):ToggleButtonGroup(initTitle,x,y,w,h)
{
}

void CheckBoxGroup::AddToggleButton(string buttonlabel)
{
	CheckBox* newbox = new CheckBox(12,13*numberofboxes,12,12);
	newbox->SetLabel(buttonlabel);
	AddControl(newbox);
	numberofboxes++;
}

void CheckBoxGroup::SetTitle(string t)
{
	ToggleButtonGroup::SetTitle(t);
}

string CheckBoxGroup::GetTitle()
{
	return title->GetLabel();
}
void CheckBoxGroup::SetBorderColor(int r,int g,int b)
{
	ToggleButtonGroup::SetBorderColor(r,g,b);

}
void CheckBoxGroup::OnPaint()
{
	ToggleButtonGroup::OnPaint();

}
void CheckBoxGroup::OnLoaded()
{
	ToggleButtonGroup::OnLoaded();

}
void CheckBoxGroup::MovePosition(int dx, int dy)
{
	ToggleButtonGroup::MovePosition(dx,dy);

}
