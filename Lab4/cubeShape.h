#pragma once
#include "lineShape.h"
#include "recShape.h"

class CubeShape : public LineShape, public RecShape {
public:
	virtual void Show(HDC);
	virtual void Editor(HDC, int, int, int, int);
	virtual Shape* New();
	long a;
};

