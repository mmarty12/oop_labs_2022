#include "framework.h"
#include "shape.h"
#include "my_editor.h"


Shape** MyEditor::pcshape = new Shape * [ARRAY_SIZE] {};

MyEditor::MyEditor(void) {}

MyEditor::~MyEditor(void) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (pcshape[i]) {
			pcshape[i] = NULL;
	 }
 }
}

void MyEditor::Start(HWND hWnd, Shape* pcsh) {
	CurrentShape = pcsh;
}

void MyEditor::OnLBdown(HWND hWnd) {
	LbDown = true;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = yend = pt.y;
	}

void MyEditor::OnLBup(HWND hWnd) {
	if (CurrentShape) {
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[idx] = CurrentShape;
		pcshape[idx]->Set(xstart, ystart, xend, yend);
		CurrentShape = CurrentShape->New();
		InvalidateRect(hWnd, NULL, TRUE);
		idx++;
	}
	LbDown = false;
}

void MyEditor::OnMouseMove(HWND hWnd) {
	if (!LbDown) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	if (CurrentShape) CurrentShape->Editor(hdc, xstart, ystart, xend, yend);
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;
    if (CurrentShape)  CurrentShape->Editor(hdc, xstart, ystart, xend, yend);
    SelectObject(hdc, hPenOld);
    DeleteObject(hPen);
    ReleaseDC(hWnd, hdc);
}

void MyEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (pcshape[i]) pcshape[i]->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}