#include "StdAfx.h"
#include "Label.h"
#include "Graphix.h"

using namespace std;

Label::Label(int x, int y) : ControlBaseExtended(x,y,0,0)
{
	textColorR = textColorG = textColorB = 0;
}

Label::Label(string l, int x, int y) : ControlBaseExtended(x, y, 0, 0)
{
	textColorR = textColorG = textColorB = 0;
	label = l;
}


string Label::GetLabel()
{
	return label;
}

void Label::SetLabel(string s)
{
	label = s;
}

void Label::SetLabelColor(int r,int g,int b)
{
	textColorR = r;
	textColorG = g;
	textColorB = b;
}

void Label::OnPaint()
{
		SetColor(textColorR,textColorG,textColorB);
		DrawString(label,X,Y);
}

void Label::MovePosition(int dx, int dy)
{
	ControlBaseExtended::MovePosition(dx, dy);
}

	
