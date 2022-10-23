#pragma once
#include "framework.h"
#include "editor.h"
#include "shape.h"

#define ARRAY_SIZE 114

extern Shape* pcshape[];
class ShapeEditor : public Editor {
protected:
	POINT pt;
	HMENU hMenu, hSubMenu;
	int idx = 0;
	int xstart = NULL;
	int ystart, xend, yend;
public:
	ShapeEditor(void);
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0; //додатковий інтерфейсний метод 
};