#pragma once
#include "stdafx.h"
#include "Graphix.h"
#include <vector>

using namespace std;

class Container : public ControlBase
{
private:
	vector<ControlBase*> controlList; // The order of the elements in this list represents the Z value. The last added control will be in front.
public:
	Container();
	Container(int locX, int locY, int width, int height);
	~Container();

	void AddControl(ControlBase *control);

	virtual void OnLoaded();
	virtual void OnPaint();
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);
};