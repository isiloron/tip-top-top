#pragma once
#include "ControlBase.h"

class ControlBaseExtended : public ControlBase
{
private:
	int zVal;
public:
	ControlBaseExtended(int xPos, int yPos, int width, int height);

	void SetZ(int z) { zVal = z; }
	int GetZ() { return zVal; }

	static bool Compare(ControlBaseExtended* a, ControlBaseExtended* b);

	virtual void MovePosition(int dx, int dy);
};