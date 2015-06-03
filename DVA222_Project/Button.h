#pragma once
#include "stdafx.h"
#include "Graphix.h"
#include "Label.h"
#include "ImageBox.h"

class Button : public ControlBase
{
protected:
	Bitmap *normal, *hover, *press;
	ImageBox *image;
	Label *label;
	bool mouseOver, pressed;
public:
	Button();
	Button(int locX, int locY, int width, int height);
	~Button();

	void LoadBitmaps(string normal, string hover, string press);
	void LoadNormalBitmap(string filename);
	void LoadHoverBitmap(string filename);
	void LoadPressBitmap(string filename);

	void SetLabel(string text);

	virtual void OnLoaded();
	virtual void OnPaint(void);
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);

};