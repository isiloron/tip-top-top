#pragma once
#include "ToggleButtonGroup.h"
#include "Label.h"
#include "CheckBox.h"
#include "Graphix.h"

using namespace std;

class CheckBoxGroup : public ToggleButtonGroup
{
public:
	CheckBoxGroup(string t,int x,int y,int w,int h);

	void AddToggleButton(string buttonlabel);
};