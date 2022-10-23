#include "framework.h"
#include "editor.h"
#include "shape.h"
#include "shape_editor.h"
#include "ShapeEditor.h"
#include "pointEditor.h"
#include "lineEditor.h"
#include "recEditor.h"
#include "ellipseEditor.h"

ShapeEditor* pse = NULL;

ShapeObjectsEditor::ShapeObjectsEditor(void) {
	pse = NULL;
}

ShapeObjectsEditor::~ShapeObjectsEditor(void) {}

void ShapeObjectsEditor::StartPointEditor() {
	if (pse) delete pse;
	pse = new PointEditor;
}

void ShapeObjectsEditor::StartLineEditor() {
	if (pse) delete pse;
	pse = new LineEditor;
}

void ShapeObjectsEditor::StartRecEditor() {
	if (pse) delete pse;
	pse = new RecEditor;
}

void ShapeObjectsEditor::StartEllipseEditor() {
	if (pse) delete pse;
	pse = new EllipseEditor;
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse) pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse) pse->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse) pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd) {
	if (pse) pse->OnPaint(hWnd);
}

void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (pse) pse->OnInitMenuPopup(hWnd, wParam);
}
