#pragma once
#include "stdafx.h"
#include "ToggleButton.h"


class CheckBox : public ToggleButton
{
public:
	CheckBox();
	CheckBox(int locX, int locY, int width, int height);

	virtual void OnMouseMove(int button, int x, int y);
};