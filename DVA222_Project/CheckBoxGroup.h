#pragma once
#include "Container.h"
#include "Label.h"
#include "CheckBox.h"
#include "Graphix.h"

using namespace std;

class CheckBoxGroup : public Container
{
private:
	Label* title;
	int numberofboxes;
	int borderR,borderG,borderB;

public:
	CheckBoxGroup(string t,int x,int y,int w,int h);

	void AddCheckBox(string boxlabel);
	void SetTitle(string t);
	string GetTitle();
	void SetBorderColor(int r,int g,int b);
	void OnPaint();
	void OnLoaded();
	void MovePosition(int dx, int dy);
};