#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
public:
	RectShape(void);
	Shape* New();

	std::wstring getName();
	void Draw(HDC);
	void Editor(HDC);
	LPCTSTR setWindowText();
};