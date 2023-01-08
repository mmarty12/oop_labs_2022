#pragma once
#include "lineShape.h"
#include "recShape.h"

class CubeShape : public LineShape, public RectShape
{
public:
	CubeShape(void);
	Shape* New();

	std::wstring getName();
	void Draw(HDC);
	void Editor(HDC);
	LPCTSTR setWindowText();
};