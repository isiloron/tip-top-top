#pragma once
#include "stdafx.h"
#include "Graphix.h"
#include "Label.h"
#include "ImageBox.h"

class Button : public ControlBase
{
protected:
	ImageBox *image;
	ImageBox *normal, *hover, *press;
	Label *label;
	bool mouseOver, pressed;
public:
	Button(int locX, int locY, int width, int height);
	~Button();

	void LoadBitmaps(string normal, string hover, string press);
	void LoadNormalBitmap(string filename);
	void LoadHoverBitmap(string filename);
	void LoadPressBitmap(string filename);

	void SetLabel(string text);
	void SetLabelColor(int r, int g, int b);

	virtual void OnLoaded();
	virtual void OnPaint(void);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void MovePosition(int x, int dy);

};