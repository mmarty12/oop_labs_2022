#include "framework.h"
#include "recShape.h"

Shape* RecShape::New() {
	return new RecShape;
}

void RecShape::Show(HDC hdc) {
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs1, ys2);
    MoveToEx(hdc, xs1, ys2, NULL);
    LineTo(hdc, xs2, ys2);
    MoveToEx(hdc, xs2, ys2, NULL);
    LineTo(hdc, xs2, ys1);
    MoveToEx(hdc, xs2, ys1, NULL);
    LineTo(hdc, xs1, ys1);
};

void RecShape::Editor(HDC hdc, int x1, int y1, int x2, int y2) {
	Rectangle(hdc, x1,  y1, x2, y2);
}