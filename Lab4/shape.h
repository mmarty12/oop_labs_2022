#pragma once
#include <windows.h>

class Shape {
protected:
	long xs1, ys1, xs2, ys2;
	long x1, y1, x2, y2;
    int idx = 0;
public:
	void Set(long x1, long y1, long x2, long y2);
	virtual void Editor(HDC, int, int, int, int) = 0;
	virtual void Show(HDC) = 0;
	virtual Shape* New() = 0;
};