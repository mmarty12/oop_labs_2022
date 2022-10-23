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
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 255));
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Rectangle(hdc, xstart, ystart, xend, yend);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;
	Rectangle(hdc, xstart, ystart, xend, yend);
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

void RecEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu) {
		CheckMenuItem(hSubMenu, ID_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_REC, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_UNCHECKED);
	}
}