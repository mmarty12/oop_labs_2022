#include "framework.h"
#include "ellipseShape.h"

void EllipseShape::Show(HDC hdc) {
	Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);
};