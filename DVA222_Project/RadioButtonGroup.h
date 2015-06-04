#pragma once
#include "Container.h"
#include "Label.h"
#include "RadioButton.h"
#include "ToggleButtonGroup.h"


class RadioButtonGroup : public ToggleButtonGroup
{
private:
	RadioButton* currentlyPressed;

public:
	RadioButtonGroup(string t,int x,int y,int w,int h);

	void AddToggleButton(string buttonlabel);
	void OnMouseDown(int button, int x, int y);

};
