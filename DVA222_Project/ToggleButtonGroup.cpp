#include "StdAfx.h"
#include "Graphix.h"
#include "ToggleButtonGroup.h"


ToggleButtonGroup::ToggleButtonGroup(string t,int x,int y,int w,int h):Container(x,y,w,h)
{
	borderR = borderG = borderB = 0;
	title = new Label(t,x,y-3);
	numberofboxes = 1;
}

void ToggleButtonGroup::AddToggleButton(string buttonlabel)
{}
void ToggleButtonGroup::SetTitle(string t)
{
	title->SetLabel(t);
}
string ToggleButtonGroup::GetTitle()
{
	return title->GetLabel();
}
void ToggleButtonGroup::SetBorderColor(int r,int g,int b)
{
		borderR = r;
		borderG = g;
		borderB = b;
}
void ToggleButtonGroup::OnPaint()
{
	SetColor(borderR,borderG,borderB);
	DrawRectangle(X,Y,Width,Height);
	Container::OnPaint();
	title->OnPaint();
}
void ToggleButtonGroup::OnLoaded()
{
	title->OnLoaded();
	Container::OnLoaded();
}
void ToggleButtonGroup::MovePosition(int dx, int dy)
{
	ControlBase::MovePosition(dx,dy);
	title->MovePosition(dx,dy);
	Container::MovePosition(dx,dy);
}
