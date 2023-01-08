#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
public:
	PointShape(void);
	Shape* New();

	std::wstring getName();
	void Draw(HDC);
	void Editor(HDC);
	LPCTSTR setWindowText();
};