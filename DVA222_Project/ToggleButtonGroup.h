#pragma once
#include "StdAfx.h"
#include "Graphix.h"
#include "Container.h"
#include "Label.h"
#include "Color.h"

using namespace std;

class ToggleButtonGroup : public Container
{
protected:
	Label* title;
	int numberOfButtons;
	Color borderColor;

public:
	ToggleButtonGroup(string t,int x,int y,int w,int h);
	~ToggleButtonGroup();

	virtual void AddToggleButton(string buttonLabel) = 0;
	void SetTitle(string t);
	string GetTitle();
	void SetBorderColor(int r,int g,int b);
	void OnPaint();
	void OnLoaded();
	void MovePosition(int dx, int dy);
};