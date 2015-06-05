#pragma once

#include "ControlBaseExtended.h"
#include "Color.h"

using namespace std;

class Label : public ControlBaseExtended
{
private:
	string label;
	Color textColor;

public:
	Label(int x,int y);
	Label(string l,int x,int y);

	string GetLabel();
	void SetLabel(string s);

	void SetLabelColor(int r,int g,int b);
	virtual void OnPaint();
	void MovePosition(int dx, int dy);

};