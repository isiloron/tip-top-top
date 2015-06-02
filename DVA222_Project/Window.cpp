#include <string>
#include <stdlib.h>
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "Window.h"
#include "Container.h"

using namespace std;

Window::Window(int x,int y,int w,int h,string title,int backR,int backG, int backB, int borderR,int borderG,int borderB): Container (x,y,w,h)
{}

void Window::SetTitle(string t)
{
	title = t;
}
string Window::GetTitle()
{
	return title;
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

void OnPaint()
{

}
