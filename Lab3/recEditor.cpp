#include "ShapeEditor.h"
#include "recShape.h"
#include "recEditor.h"
#include "Resource.h"

void RecEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = yend = pt.y;
}

void RecEditor::OnMouseMove(HWND hWnd) {
	if (!xstart) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	long xStart = xend - (2 * (xend - xstart)); //до правого верхнього кута
	long yStart = yend - (2 * (yend - ystart));
	Rectangle(hdc, xStart, yStart, xend, yend);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;
	xStart = xend - (2 * (xend - xstart)); //до правого верхнього кута
	yStart = yend - (2 * (yend - ystart));
	Rectangle(hdc, xStart, yStart, xend, yend);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}
void RecEditor::OnLBup(HWND hWnd) {
	pcshape[idx] = new RecShape;
	pcshape[idx]->Set(xstart, ystart, xend, yend);
	idx++;
	InvalidateRect(hWnd, NULL, TRUE);
	xstart = NULL;
};