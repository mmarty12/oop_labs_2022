#pragma once
#include "lineShape.h"
#include "ellipseShape.h"

class LineOOShape : public LineShape, public EllipseShape
{
public:
	LineOOShape(void);
	Shape* New();

	std::wstring getName();
	void Draw(HDC);
	void Editor(HDC);
	LPCTSTR setWindowText();
};