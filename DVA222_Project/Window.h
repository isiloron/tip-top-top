#pragma once
#include <string>
#include <stdlib.h>
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "Container.h"
#include "Label.h"

using namespace std;

class Window : public Container
{
private:
	Label *title;
	int backcolorR,backcolorG,backcolorB;
	int bordercolorR,bordercolorG,bordercolorb;

public:
	Window();
	Window(int x,int y,int w,int h,string title,int backR,int backG, int backB, int borderR,int borderG,int borderB);

	void SetTitle(string t);
	string GetTitle();
	void SetBackroundColor(int r,int g,int b);
	void SetBorderColor(int r,int g,int b);
	void OnPaint();
	void OnLoaded();
};