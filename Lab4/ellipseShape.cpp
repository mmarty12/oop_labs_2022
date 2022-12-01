#include "framework.h"
#include "ellipseShape.h"

Shape* EllipseShape::New() {
	return new EllipseShape;
}

void EllipseShape::Show(HDC hdc) {
	Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);
};

void EllipseShape::Editor(HDC hdc, int x1, int y1, int x2, int y2) {
	Arc(hdc, x1, y1, x2, y2, 0, 0, 0, 0);
}