#include "ShapeEditor.h"
#include "pointShape.h"
#include "pointEditor.h"
#include "Resource.h"

void PointEditor::OnMouseMove(HWND hWnd) {
}

void PointEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x; //кудись записуємо координати початкової точки
	ystart = yend = pt.y;
};

void PointEditor::OnLBup(HWND hWnd) {
	pcshape[idx] = new PointShape;
	pcshape[idx]->Set(xstart, ystart, xend, yend);
	idx++;
	InvalidateRect(hWnd, NULL, TRUE);
};

void PointEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu) {
		CheckMenuItem(hSubMenu, ID_POINT, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_REC, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_UNCHECKED);
	}
}