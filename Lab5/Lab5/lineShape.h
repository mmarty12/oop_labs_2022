#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
	LineShape(void);
	Shape* New();

	std::wstring getName();
	void Draw(HDC);
	void Editor(HDC);
	LPCTSTR setWindowText();
};