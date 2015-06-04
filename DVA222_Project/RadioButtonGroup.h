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
	void SetTitle(string t);
	string GetTitle();
	void SetBorderColor(int r,int g,int b);
	void OnPaint();
	void OnLoaded();
	void MovePosition(int dx, int dy);
	void OnMouseDown(int button, int x, int y);

};
