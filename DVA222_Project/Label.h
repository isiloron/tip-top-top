#pragma once
#include <string>
#include <stdlib.h>
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"


using namespace std;

class Label : public ControlBase
{
private:
	string label;
	int posx;
	int posy;

public:
	Label();
	Label(int x,int y);
	Label(string l,int x,int y);

	string GetLabel();
	void SetLabel(string s);

	void SetLabelColor(int r,int g,int b);
	virtual void OnPaint();
	void UpdatePosition(int dx, int dy);

};