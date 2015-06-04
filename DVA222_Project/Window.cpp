
#include "StdAfx.h"
#include "Graphix.h"
#include "Window.h"

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
	grab = hoverBar = hoverContents = false;
}

Window::Window(int x,int y,int w,int h,string t): Container(x,y,w,h)
{
	title = new Label(t,x+2,y-5);
	backcolorR = backcolorG = backcolorB = 200;
	bordercolorR = bordercolorG = bordercolorb = 0;
	grab = hoverBar = hoverContents=  false;
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
	Container::OnPaint();
}

void Window::OnLoaded()
{
	title->OnLoaded();
	Container::OnLoaded();
}

void Window::OnMouseDown(int button, int x, int y)
{
	if(hoverBar && button==MOUSE_LEFT)
	{
		grab = true;
		Xstart = x;
		Ystart = y;
	}
	else if (hoverContents && button == MOUSE_LEFT)
	{
		Container::OnMouseDown(button, x, y);
	}
}

void Window::OnMouseUp(int button, int x, int y)
{
	if(grab == true)
	{
		MovePosition(x - Xstart, y-Ystart);
		grab = false;
	}
	else if (hoverContents && button == MOUSE_LEFT)
	{
		Container::OnMouseUp(button,x,y);
	}
}

void Window::OnMouseMove(int button, int x, int y)
{
	if(grab == true)
	{
		MovePosition(x - Xstart, y - Ystart);
		Xstart = x;
		Ystart = y;
	}
	
	if (x>X && x < X+Width && y >Y-15 && y < Y)
		hoverBar = true;
	else
    {
		hoverBar= false;
    }
	
	if (x>X && x<X + Width && y>Y && y < Y + Height)
	{
		hoverContents = true;
		Container::OnMouseMove(button,x,y);
	}
	else
	{
		hoverContents = false;
	}

}

void Window::MovePosition(int dx, int dy)
{
	ControlBaseExtended::MovePosition(dx, dy);
	title->MovePosition(dx, dy);
	Container::MovePosition(dx, dy);
}