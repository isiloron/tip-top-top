#include "stdafx.h"
#include "ControlBaseExtended.h"

ControlBaseExtended::ControlBaseExtended(int xPos, int yPos, int width, int height)
:ControlBase(xPos, yPos, width, height)
{
	zVal = 0;
}

void ControlBaseExtended::MovePosition(int dx, int dy)
{
	X += dx;
	Y += dy;
}

bool ControlBaseExtended::Compare(ControlBaseExtended* a, ControlBaseExtended* b)
{
	return a->GetZ() > b->GetZ();
}