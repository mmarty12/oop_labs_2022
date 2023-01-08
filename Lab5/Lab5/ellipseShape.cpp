#include "ellipseShape.h"

EllipseShape::EllipseShape() {}

Shape* EllipseShape::New()
{
	return new EllipseShape;
}

std::wstring EllipseShape::getName()
{
	return L"Ελ³ορ";
}

void EllipseShape::Draw(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, xstart, ystart, xend, yend);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void EllipseShape::Editor(HDC hdc)
{
	HPEN hPenOld, hPen;
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, xstart, ystart, xend, yend);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

LPCTSTR EllipseShape::setWindowText()
{
	return  L"Ελ³ορ";
}