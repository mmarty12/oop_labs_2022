#include "shape_editor.h"
#include "ShapeEditor.h"

Shape* pcshape[ARRAY_SIZE];

ShapeEditor::ShapeEditor(void) {
	for (int i = 0; i < ARRAY_SIZE; i++) 
		if (!pcshape[i]) {
			idx = i;
			break;
		}
}

void ShapeEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < ARRAY_SIZE; i++) 
		if (pcshape[i]) {
			pcshape[i]->Show(hdc);
		}
		else break;
		EndPaint(hWnd, &ps);
}