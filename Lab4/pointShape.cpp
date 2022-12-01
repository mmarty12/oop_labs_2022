#include "framework.h"
#include "pointShape.h"
#include <commctrl.h>


Shape* PointShape::New() {
	return new PointShape;
}

void PointShape::Show(HDC hdc) {
	SetPixel(hdc, xs1, ys1, 0x00000000);
	SetPixel(hdc, xs1 - 2, ys1, 0x00000000);
	SetPixel(hdc, xs1 - 1, ys1, 0x00000000);
	SetPixel(hdc, xs1 + 1, ys1, 0x00000000);
	SetPixel(hdc, xs1 + 2, ys1, 0x00000000);
	SetPixel(hdc, xs1, ys1 - 2, 0x00000000);
	SetPixel(hdc, xs1, ys1 - 1, 0x00000000);
	SetPixel(hdc, xs1, ys1 + 1, 0x00000000);
	SetPixel(hdc, xs1, ys1 + 2, 0x00000000);
	SetPixel(hdc, xs1 - 1, ys1 - 1, 0x00000000);
	SetPixel(hdc, xs1 + 1, ys1 - 1, 0x00000000);
	SetPixel(hdc, xs1 - 1, ys1 + 1, 0x00000000);
	SetPixel(hdc, xs1 + 1, ys1 + 1, 0x00000000);
};

void PointShape::Editor(HDC, int, int, int, int) {};