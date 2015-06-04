#pragma once
#include "ToggleButtonGroup.h"
#include "Label.h"
#include "CheckBox.h"
#include "Graphix.h"

using namespace std;

class CheckBoxGroup : public ToggleButtonGroup
{
private:
	//Label* title;
	//int numberofboxes;
	//int borderR,borderG,borderB;

public:
	CheckBoxGroup(string t,int x,int y,int w,int h);

	void AddToggleButton(string buttonlabel);
	void SetTitle(string t);
	string GetTitle();
	void SetBorderColor(int r,int g,int b);
	void OnPaint();
	void OnLoaded();
	void MovePosition(int dx, int dy);
};