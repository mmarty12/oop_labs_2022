#include "cubeShape.h"

CubeShape::CubeShape() {}

Shape* CubeShape::New()
{
	return new CubeShape;
}

std::wstring CubeShape::getName()
{
	return L" Û·";
}

void CubeShape::Draw(HDC hdc)
{
	int x1, x2, y1, y2;

	RectShape::Draw(hdc);

	x1 = xstart; y1 = ystart; x2 = xend; y2 = yend;

	int xStart = x2 - (2 * (x2 - x1));
	int yStart = y2 - (2 * (y2 - y1));

	int xEnd = 2 * x2 - x1;
	int yEnd = y1 - (2 * (y2 - y1));

	LineShape::Set(x1, y1, xStart, y2);
	LineShape::Draw(hdc);

	LineShape::Set(xStart, yStart, x1, yEnd);
	LineShape::Draw(hdc);

	LineShape::Set(x2, yStart, xEnd, yEnd);
	LineShape::Draw(hdc);

	LineShape::Set(x2, y2, xEnd, y1);
	LineShape::Draw(hdc);

	LineShape::Set(x1, y1, x1, yEnd);
	LineShape::Draw(hdc);

	LineShape::Set(x1, yEnd, xEnd, yEnd);
	LineShape::Draw(hdc);

	LineShape::Set(xEnd, yEnd, xEnd, y1);
	LineShape::Draw(hdc);

	LineShape::Set(xEnd, y1, x1, y1);
	LineShape::Draw(hdc);

	xstart = x1; ystart = y1; xend = x2; yend = y2;
}

void CubeShape::Editor(HDC hdc)
{
	Draw(hdc);
}

LPCTSTR CubeShape::setWindowText()
{
	return  L" Û·";
}