#pragma once
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>
#include "Container.h"
#include "Label.h"

using namespace std;

class RadioButtonGroup : public Container
{
private:
	Label* title;
	int numberofboxes;
	int borderR,borderG,borderB;

public:
	RadioButtonGroup(string t,int x,int y,int w,int h);

	void AddRadioButton(string boxlabel);
	void SetTitle(string t);
	string GetTitle();
	void SetBorderColor(int r,int g,int b);
	void OnPaint();
	void OnLoaded();
	void UpdatePosition(int dx, int dy);
};
