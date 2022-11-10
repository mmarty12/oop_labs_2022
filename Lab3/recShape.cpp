#include "framework.h"
#include "recShape.h"

void RecShape::Show(HDC hdc) {
	HBRUSH hBrush, hBrushOld;
	filling = RGB(255, 255, 255);
	hBrush = (HBRUSH)CreateSolidBrush(filling);
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	long xStart = xs2 - (2 * (xs2 - xs1)); //до правого верхнього кута
	long yStart = ys2 - (2 * (ys2 - ys1));
	Rectangle(hdc, xStart, yStart, xs2, ys2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
};