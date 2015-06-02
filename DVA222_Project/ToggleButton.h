#pragma once
#include "stdafx.h"
#include "Button.h"

class ToggleButton : public Button
{
public:
	ToggleButton();
	ToggleButton(int locX, int locY, int width, int height);

	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
};
