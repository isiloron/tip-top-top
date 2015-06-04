#pragma once
#include "Container.h"
#include "Color.h"

class Panel : public Container
{
private:
	Color backgroundColor;

public:
	Panel(int locX, int locY, int width, int height);

	void SetBackgroundColor(int r, int g, int b);

	virtual void OnPaint(void);
	virtual void MovePosition(int dx, int dy);
};