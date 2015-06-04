
#include "StdAfx.h"
#include "Graphix.h"
#include "Window.h"

using namespace std;


Window::Window(int x,int y,int w,int h,string t): Container(x,y,w,h)
{
	title = new Label(t,x+2,y-5);
	backgrundColor = Color( 200,200,200);
	borderColor = Color(0, 0, 0);
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
	backgrundColor.SetRGB(r,g,b);
}
void Window::SetBorderColor(int r,int g,int b)
{
	borderColor.SetRGB(r, g, b);
}

void Window::OnPaint()
{
	title->OnPaint();
	backgrundColor.DrawWith();
	FillRectangle(X,Y,Width,Height);
	
	borderColor.DrawWith();
	DrawRectangle(X,Y,Width,Height); // border
	DrawRectangle(X,Y-15,Width,15); // the bar
	
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