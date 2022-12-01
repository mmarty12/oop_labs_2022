#pragma once
#include "lineShape.h"
#include "ellipseShape.h"

class LineOOShape : public LineShape, public EllipseShape {
public:
	virtual void Show(HDC);
	virtual void Editor(HDC, int, int, int, int);
	virtual Shape* New();
	long a;
};
