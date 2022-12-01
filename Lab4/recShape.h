#pragma once
#include "shape.h"

class RecShape : public virtual Shape {
public:
	virtual void Show(HDC);
	virtual void Editor(HDC, int, int, int, int);
	virtual Shape* New();
};