#pragma once
#include "stdafx.h"
#include "ToggleButton.h"


class RadioButton : public ToggleButton
{
public:
	RadioButton(int locX, int locY, int width, int height);

	bool IsPressed() { return Button::pressed; }
	void SetPressed(bool b) {Button::pressed = b;}
};