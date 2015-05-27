#pragma once
#include "stdafx.h"
#include "Graphix.h"
#include "Label.h"

class Button : public ControlBase
{
private:
	Bitmap *normal, *hover, *press;
	Label *label;
public:
	Button();
	Button(int locX, int locY, int width, int height);
	~Button();



};