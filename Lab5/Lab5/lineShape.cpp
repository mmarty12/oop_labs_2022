#include "lineShape.h"

LineShape::LineShape() {}

Shape* LineShape::New()
{
	return new LineShape;
}

std::wstring LineShape::getName()
{
	return L"Ë³í³ÿ";
}

void LineShape::Draw(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
}

void LineShape::Editor(HDC hdc)
{
	Draw(hdc);
}

LPCTSTR  LineShape::setWindowText()
{
	return  L"Ë³í³ÿ";
}