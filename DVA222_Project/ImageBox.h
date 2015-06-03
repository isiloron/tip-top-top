#pragma once
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include <string>
#include <stdlib.h>

using namespace std;

class ImageBox : public ControlBase
{
private:
	Bitmap *boxtexture;
	string texturepath;

public:
	ImageBox();
	ImageBox(int x,int y,int w,int h);
	ImageBox(string path,int x,int y,int w,int h);

	~ImageBox();
	
	void OnPaint();
	void OnLoaded();
	void SetTexture(string t);
	void SetBitmap(Bitmap* bitmap);
};