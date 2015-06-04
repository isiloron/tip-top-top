#pragma once
#include "ControlBaseExtended.h"
#include "Graphix.h"

using namespace std;

class ImageBox : public ControlBaseExtended
{
private:
	Bitmap *boxtexture;
	string texturepath;

public:
	ImageBox(int x,int y,int w,int h);
	ImageBox(string path,int x,int y,int w,int h);

	~ImageBox();
	
	void OnPaint();
	void OnLoaded();
	void SetTexture(string t);
	void SetBitmap(Bitmap* bitmap);
};