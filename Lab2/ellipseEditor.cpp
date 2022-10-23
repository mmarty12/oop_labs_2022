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
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 255));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	long xStart = xend - (2 * (xend - xstart)); //до правого верхнього кута
	long yStart = yend - (2 * (yend - ystart));
	Ellipse(hdc, xStart, yStart, xend, yend);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;
	xStart = xend - (2 * (xend - xstart)); //до правого верхнього кута
	yStart = yend - (2 * (yend - ystart));
	Ellipse(hdc, xStart, yStart, xend, yend);
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

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu) {
		CheckMenuItem(hSubMenu, ID_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_REC, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_CHECKED);
	}
};
