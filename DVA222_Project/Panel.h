#pragma once
#include "stdafx.h"
#include "Container.h"

class Panel : public Container
{
private:
	int r, g, b;

public:
	Panel(int locX, int locY, int width, int height);

	void SetBackgroundColor(int r, int g, int b);

	virtual void OnPaint(void);
	virtual void UpdatePosition(int dx, int dy);
};