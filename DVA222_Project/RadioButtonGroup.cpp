#include "StdAfx.h"
#include "Graphix.h"
#include "RadioButtonGroup.h"


RadioButtonGroup::RadioButtonGroup(string initTitle,int x,int y,int w,int h):ToggleButtonGroup(initTitle,x,y,w,h)
{
	borderR = borderG = borderB = 0;
	currentlyPressed = NULL;
}

void RadioButtonGroup::AddToggleButton(string buttonlabel)
{
	RadioButton* newRadio = new RadioButton(12,13*numberofboxes,12,12);
	newRadio->SetLabel(buttonlabel);
	AddControl(newRadio);
	numberofboxes++;
	currentlyPressed = NULL;
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
	ToggleButtonGroup::SetBorderColor(r,g,b);

}
void RadioButtonGroup::OnPaint()
{
	ToggleButtonGroup::OnPaint();
	SetColor(borderR,borderG,borderB);
	DrawRectangle(X,Y,Width,Height);
	Container::OnPaint();
	title->OnPaint();
}
void RadioButtonGroup::OnLoaded()
{
	ToggleButtonGroup::OnLoaded();

}

void RadioButtonGroup::OnMouseDown(int button, int x, int y)
{
	Container::OnMouseDown(button,x,y);

	RadioButton* newPressed = NULL;
	for(size_t i = 0; i<controlList.size();i++)
	{
		RadioButton* button = (RadioButton*)controlList[i];
		if(button->IsPressed() && button != currentlyPressed)
		{
			newPressed = button;
		}
	}

	if (currentlyPressed == NULL && newPressed != NULL)
	{
		currentlyPressed = newPressed;
	}
	else if (currentlyPressed != NULL && newPressed == NULL)
	{
		if (!currentlyPressed->IsPressed())
			currentlyPressed = NULL;
	}
	else if (currentlyPressed != NULL && newPressed != NULL)
	{
		currentlyPressed->SetPressed(false);
		currentlyPressed = newPressed;
	}

}

void RadioButtonGroup::MovePosition(int dx, int dy)
{
	ToggleButtonGroup::MovePosition(dx,dy);

}
