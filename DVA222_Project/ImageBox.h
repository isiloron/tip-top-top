#pragma once
#include <string>
#include <stdlib.h>
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"


using namespace std;

class ImageBox : public ControlBase
{
private:
	Bitmap *boxtexture;
	string texturepath;

public:
	ImageBox();
	ImageBox(string path,int x,int y,int w,int h);

	~ImageBox();
	
	void OnPaint();
	void OnLoaded();
	void SetTexture(string t);
};