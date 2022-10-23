#pragma once
#include <windows.h>

class Shape {
protected:
	long xs1, ys1, xs2, ys2;
	long colour, filling;
public:
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC) = 0;
};