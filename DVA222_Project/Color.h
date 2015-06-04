#pragma once

#include "Graphix.h"

class Color
{
private:
	int r,g,b;

	int CheckRange(int c)
	{
		if (c < 0)
		{
			return 0;
		}
		else if(c > 255)
		{
			return 255;
		}
		else
		{
			return c;
		}
	}

public:
	Color(int r = 0, int g = 0, int b = 0)
	{
		SetRGB(r, g, b);
	}


	void SetRGB(int r, int g, int b)
	{
			this->r = CheckRange(r);
			this->g = CheckRange(g);
			this->b = CheckRange(b);
	}

	void DrawWith()
	{
		SetColor(r, g, b);
	}

};