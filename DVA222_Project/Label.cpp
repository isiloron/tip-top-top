#include "StdAfx.h"
#include "MyButton.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include "Label.h"

using namespace std;

Label::Label()
{}

Label::Label(string l,int posx ,int posy)
{
	label = l;
	DrawString(l,posx,posy);
	glColor3f(0,0,0);
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
	
