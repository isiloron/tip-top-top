#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>
#include "Container.h"
#include "Label.h"
#include "CheckBox.h"
#include "CheckBoxGroup.h"

using namespace std;

CheckBoxGroup::CheckBoxGroup(string initTitle,int x,int y,int w,int h):Container(x,y,w,h)
{
	title = new Label(initTitle,x,y-3);
	numberofboxes = 1;
}

void CheckBoxGroup::AddCheckBox(string boxlabel)
{
	CheckBox* newbox = new CheckBox(X+10,Y+15*numberofboxes,12,12);
	newbox->SetLabel(boxlabel);
	AddControl(newbox);
	numberofboxes++;
}

void CheckBoxGroup::SetTitle(string t)
{
	title->SetLabel(t);
}

string CheckBoxGroup::GetTitle()
{
	return title->GetLabel();
}
void CheckBoxGroup::SetBorderColor(int r,int g,int b)
{
		borderR = r;
		borderG = g;
		borderB = b;
}
void CheckBoxGroup::OnPaint()
{
	SetColor(borderR,borderG,borderB);
	DrawRectangle(X,Y,Width,Height);
	Container::OnPaint();
	title->OnPaint();
}
void CheckBoxGroup::OnLoaded()
{
	title->OnLoaded();
	Container::OnLoaded();
}
void CheckBoxGroup::MovePosition(int dx, int dy)
{
	ControlBase::MovePosition(dx,dy);
	title->MovePosition(dx,dy);
	Container::MovePosition(dx,dy);
}
