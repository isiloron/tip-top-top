
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "Window.h"
#include "Container.h"
#include "Label.h"
#include <string>
#include <stdlib.h>

using namespace std;

Window::Window(int x,int y,int w,int h,string t,int backR,int backG, int backB, int borderR,int borderG,int borderB): Container (x,y,w,h)
{
	title = new Label(t,x+2,y-5);
	backcolorR = backR;
	backcolorG = backG;
	backcolorB = backB;
	bordercolorR = borderR;
	bordercolorG = borderG;
	bordercolorb = borderB;
	grab = hover = false;
}

Window::Window(int x,int y,int w,int h,string t): Container(x,y,w,h)
{
	title = new Label(t,x+2,y-5);
	backcolorR = backcolorG = backcolorB = 200;
	bordercolorR = bordercolorG = bordercolorb = 0;
	grab = hover=  false;
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
	title->OnPaint();
	SetColor(backcolorR,backcolorG,backcolorB);
	FillRectangle(X,Y,Width,Height);
	SetColor(bordercolorR,bordercolorG,bordercolorb);
	DrawRectangle(X,Y,Width,Height);
	DrawRectangle(X,Y-15,Width,15);
}

void Window::OnLoaded()
{

}

void Window::OnMouseDown(int button, int x, int y)
{
	if(hover && button==MOUSE_LEFT)
	{
		grab = true;
		Xstart = x;
		Ystart = y;
	}
}

void Window::OnMouseUp(int button, int x, int y)
{
	if(grab == true)
	{
		UpdatePosition(x - Xstart, y-Ystart);
		grab = false;
	}
}

void Window::OnMouseMove(int button, int x, int y)
{
	if(grab == true)
	{
		UpdatePosition(x - Xstart, y-Ystart);
		Xstart = x;
		Ystart = y;
	}
	else if (x>X && x < X+Width && y >Y-15 && y < Y)
		hover = true;
	else
    {
		hover= false;
    }
	
}

void Window::UpdatePosition(int dx, int dy)
{
	ControlBase::UpdatePosition(dx,dy);
	title->UpdatePosition(dx, dy);
	Container::UpdatePosition(dx,dy);
}