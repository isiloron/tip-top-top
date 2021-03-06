#include "StdAfx.h"
#include "Graphix.h"
#include "RadioButtonGroup.h"


RadioButtonGroup::RadioButtonGroup(string initTitle,int x,int y,int w,int h):ToggleButtonGroup(initTitle,x,y,w,h)
{
	currentlyPressed = NULL;
}

void RadioButtonGroup::AddToggleButton(string buttonlabel)
{
	RadioButton* newRadio = new RadioButton(12, 13 * numberOfButtons, 12, 12);
	newRadio->SetLabel(buttonlabel);
	AddControl(newRadio);
	numberOfButtons++;
}

void RadioButtonGroup::OnMouseDown(int button, int x, int y)
{
	Container::OnMouseDown(button,x,y);

	RadioButton* newPressed = NULL;
	for(size_t i = 0; i<controlList.size();i++)
	{
		newPressed = (RadioButton*)controlList[i];
		if (newPressed->IsPressed() && newPressed != currentlyPressed)
		{
			break;
		}
		else
		{
			newPressed = NULL;
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
