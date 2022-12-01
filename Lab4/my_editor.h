#pragma once
#include "framework.h"
#include "shape.h"

#define ARRAY_SIZE 114

class MyEditor {
private:
	static Shape** pcshape;
	Shape* CurrentShape;
	int idx = 0;
	bool LbDown = false;
	POINT pt;
	int xstart = NULL;
	int ystart, xend, yend;
public:
	MyEditor(void);
	~MyEditor();
	void Start(HWND, Shape*);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};