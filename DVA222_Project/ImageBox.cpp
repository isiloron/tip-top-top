#include <string>
#include <stdlib.h>
#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "ImageBox.h"


using namespace std;

ImageBox::ImageBox(){}

ImageBox::ImageBox(string path, int x,int y,int w,int h): ControlBase(x,y,w,h)
{
	texturepath = path;
}

ImageBox::~ImageBox()
{
	delete boxtexture;
}

void ImageBox::OnPaint()
{
	DrawBitmap(*boxtexture,X,Y,Width,Height);
}

void ImageBox::OnLoaded()
{
	boxtexture = new Bitmap(texturepath);
}

void ImageBox::SetTexture(string t)
{
}