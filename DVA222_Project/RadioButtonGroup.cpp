#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>
#include "Container.h"
#include "Label.h"
#include "RadioButton.h"
#include "RadioButtonGroup.h"

using namespace std;

RadioButtonGroup::RadioButtonGroup(string initTitle,int x,int y,int w,int h):Container(x,y,w,h)
{
	title = new Label(initTitle,x,y-3);
	numberofboxes = 1;
	borderR = borderG = borderB = 0;
}

void RadioButtonGroup::AddRadioButton(string Radiolabel)
{
	RadioButton* newRadio = new RadioButton(X+10,Y+15*numberofboxes,12,12);
	newRadio->SetLabel(Radiolabel);
	AddControl(newRadio);
	numberofboxes++;
}

void RadioButtonGroup::SetTitle(string t)
{
	title->SetLabel(t);
}

string RadioButtonGroup::GetTitle()
{
	return title->GetLabel();
}
void RadioButtonGroup::SetBorderColor(int r,int g,int b)
{
		borderR = r;
		borderG = g;
		borderB = b;
}
void RadioButtonGroup::OnPaint()
{
	SetColor(borderR,borderG,borderB);
	DrawRectangle(X,Y,Width,Height);
	Container::OnPaint();
	title->OnPaint();
}
void RadioButtonGroup::OnLoaded()
{
	title->OnLoaded();
	Container::OnLoaded();
}
void RadioButtonGroup::UpdatePosition(int dx, int dy)
{
	ControlBase::UpdatePosition(dx,dy);
	title->UpdatePosition(dx,dy);
	Container::UpdatePosition(dx,dy);
}