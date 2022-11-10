#include "ShapeEditor.h"
#include "lineEditor.h"
#include "lineShape.h"
#include "Resource.h"

void LineEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = yend = pt.y;
}

void LineEditor::OnMouseMove(HWND hWnd) {
	if (!xstart) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 20));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}
void LineEditor::OnLBup(HWND hWnd) {
	pcshape[idx] = new LineShape;
	pcshape[idx]->Set(xstart, ystart, xend, yend);
	idx++;
	InvalidateRect(hWnd, NULL, TRUE);
	xstart = NULL;
};