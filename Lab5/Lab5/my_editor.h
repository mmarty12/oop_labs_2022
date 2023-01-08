#pragma once
#include "shape.h"
#include "pointShape.h"
#include "lineShape.h"
#include "recShape.h"
#include "ellipseShape.h"
#include "cubeShape.h"
#include "lineOOShape.h"
#include "toolbar.h"
#include <string>

#define ARRAY_SIZE		114

class MyEditor
{
private:
	static MyEditor* p_instance;
	MyEditor() {}
	MyEditor(const MyEditor&);
	MyEditor& operator = (MyEditor&);

	ToolBar ToolBar;
	Shape** pshape = new Shape * [ARRAY_SIZE] {};;
	int i = 0;
	Shape* parentShape = NULL;
	long xstart = 0, ystart = 0, xend = 0, yend = 0;
public:
	static MyEditor* getInstance();

	void Start(Shape*, HWND, UINT, UINT, LPARAM);
	void OnLBdown(HWND);
	std::wstring OnLBup(HWND);
	void RemoveItem(int);
	void OnMouseMove(HWND);
	void OnPaint(HWND, int);
	void OnCreate(HWND, HINSTANCE);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnSize(HWND);
};