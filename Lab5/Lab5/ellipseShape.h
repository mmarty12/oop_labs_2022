#pragma once
#include "shape.h"

class EllipseShape : virtual public Shape
{
public:
	EllipseShape(void);
	Shape* New();

	std::wstring getName();
	void Draw(HDC);
	void Editor(HDC);
	LPCTSTR setWindowText();
};