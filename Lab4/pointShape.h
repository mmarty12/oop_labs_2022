#pragma once
#include "shape.h"

class PointShape : public virtual Shape {
public:
	virtual void Show(HDC);
	virtual void Editor(HDC, int, int, int, int);
	virtual Shape* New();
};