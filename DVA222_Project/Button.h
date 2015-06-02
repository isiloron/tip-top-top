#pragma once
#include "stdafx.h"
#include "Graphix.h"
#include "Label.h"
#include "ImageBox.h"

class Button : public ControlBase
{
private:
	Bitmap *normal, *hover, *press;
	ImageBox *image;
	Label *label;
	bool mouseOver, pressed;
public:
	Button();
	Button(int locX, int locY, int width, int height);
	~Button();

	void SetBitmaps(string normal, string hover, string press);
	void SetNormalBitmap(string filename);
	void SetHoverBitmap(string filename);
	void SetPressBitmap(string filename);

	virtual void OnLoaded();
	virtual void OnPaint(void);
	virtual void OnKeyboard(unsigned char key, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);

};