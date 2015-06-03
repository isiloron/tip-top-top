#pragma once
#include "stdafx.h"
#include "ToggleButton.h"


class RadioButton : public ToggleButton
{
public:
	RadioButton();
	RadioButton(int locX, int locY, int width, int height);

	virtual void OnMouseMove(int button, int x, int y);
};