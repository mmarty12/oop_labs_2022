#pragma once
#include "framework.h"

class ShapeObjectsEditor {
public:
	ShapeObjectsEditor(void);
	~ShapeObjectsEditor();
	void StartPointEditor();
	void StartLineEditor();
	void StartRecEditor();
	void StartEllipseEditor();
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM); //відповідно варіанту завдання
};

