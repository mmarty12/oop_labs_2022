#include "ShapeEditor.h"
#include "ellipseShape.h"
#include "ellipseEditor.h"
#include "Resource.h"

void EllipseEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = yend = pt.y;
}

void EllipseEditor::OnMouseMove(HWND hWnd) {
	if (!xstart) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, xstart, ystart, xend, yend);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;
	Ellipse(hdc, xstart, ystart, xend, yend);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

void EllipseEditor::OnLBup(HWND hWnd) {
	pcshape[idx] = new EllipseShape;
	pcshape[idx]->Set(xstart, ystart, xend, yend);
	idx++;
	InvalidateRect(hWnd, NULL, TRUE);
	xstart = NULL;
};