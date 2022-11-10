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
