#include "pointShape.h"
#include "framework.h"

PointShape::PointShape() {}

Shape* PointShape::New()
{
	return new PointShape;
}

std::wstring PointShape::getName()
{
	xstart = xend;
	ystart = yend;
	xend = 0;
	yend = 0;
	return L"Крапка";
}

void PointShape::Draw(HDC hdc)
{
	SetPixel(hdc, xstart, ystart, 0x00000000);
}

void PointShape::Editor(HDC hdc) {}

LPCTSTR PointShape::setWindowText()
{
	return  L"Крапка";
}