#include "StdAfx.h"
#include "MyButton.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include "Label.h"

using namespace std;

Label::Label()
{}

Label::Label(int x, int y) : ControlBase(x,y,0,0)
{
}

Label::Label(string l, int x, int y) :Label(x, y)
{
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

}

void Label::OnPaint()
{
		SetColor(0,0,0);
		DrawString(label,X,Y);
}

void Label::MovePosition(int dx, int dy)
{
	X = X - dx;
	Y = Y - dy;
}

	
