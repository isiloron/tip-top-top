#include <string>
#include <stdlib.h>
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "Window.h"
#include "Container.h"
#include "Label.h"

using namespace std;

Window::Window(int x,int y,int w,int h,string t,int backR,int backG, int backB, int borderR,int borderG,int borderB): Container (x,y,w,h)
{
	title = new Label(t,x,y);
	backcolorR = backR;
	backcolorG = backG;
	backcolorB = backB;
	bordercolorR = borderR;
	bordercolorG = borderG;
	bordercolorb = borderB;
}

Window::Window(int x,int y,int w,int h,string t): Container(x,y,w,h)
{
	title = new Label(t,x,y);
	backcolorR = backcolorG = backcolorB = 200;
	bordercolorR = bordercolorG = bordercolorb = 0;
}

void Window::SetTitle(string t)
{
	title->SetLabel(t);
}
string Window::GetTitle()
{
	return title->GetLabel();
}
void Window::SetBackroundColor(int r,int g,int b)
{
	backcolorR = r;
	backcolorG = g;
	backcolorB = b;
}
void Window::SetBorderColor(int r,int g,int b)
{
	bordercolorR = r;
	bordercolorG = g;
	bordercolorb = b;
}

void Window::OnPaint()
{
	SetColor(backcolorR,backcolorG,backcolorB);
	FillRectangle(X,Y,Width,Height);
	SetColor(bordercolorR,bordercolorG,bordercolorb);
	DrawRectangle(X,Y,Width,Height);
}

void Window::OnLoaded()
{

}