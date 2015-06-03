#include "StdAfx.h"
#include "Graphix.h"
#include "glut.h"
#include "ImageBox.h"
#include <string>
#include <stdlib.h>

using namespace std;

ImageBox::ImageBox(){}

ImageBox::ImageBox(int x,int y,int w,int h):ControlBase(x,y,w,h)
{

}


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

void ImageBox::SetBitmap(Bitmap* bitmap)
{
	delete boxtexture;
	boxtexture = bitmap;
}