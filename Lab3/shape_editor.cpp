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

ShapeObjectsEditor::ShapeObjectsEditor(void) {}
ShapeObjectsEditor::~ShapeObjectsEditor(void) {}

void ShapeObjectsEditor::StartPointEditor(HWND hWnd) {
	if (pse) delete pse;
	pse = new PointEditor;
	SetWindowText(hWnd, L"Режим вводу: крапка");
}

void ShapeObjectsEditor::StartLineEditor(HWND hWnd) {
	if (pse) delete pse;
	pse = new LineEditor;
	SetWindowText(hWnd, L"Режим вводу: лінія");
}

void ShapeObjectsEditor::StartRecEditor(HWND hWnd) {
	if (pse) delete pse;
	pse = new RecEditor;
	SetWindowText(hWnd, L"Режим вводу: прямокутник");
}

void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd) {
	if (pse) delete pse;
	pse = new EllipseEditor;
	SetWindowText(hWnd, L"Режим вводу: еліпс");
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