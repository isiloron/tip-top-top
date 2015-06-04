#pragma once

#include "ControlBaseExtended.h"

using namespace std;

class Label : public ControlBaseExtended
{
private:
	string label;
	int textColorR,textColorG,textColorB;

public:
	Label(int x,int y);
	Label(string l,int x,int y);

	string GetLabel();
	void SetLabel(string s);

	void SetLabelColor(int r,int g,int b);
	virtual void OnPaint();
	void MovePosition(int dx, int dy);

};