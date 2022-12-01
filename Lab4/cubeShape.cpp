#include "framework.h"
#include "cubeShape.h"
#include "resource.h"

Shape* CubeShape::New() {
	return new CubeShape;
}

void CubeShape::Show(HDC hdc) {
    RecShape::Show(hdc);
	
	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;
	
	a = abs((x2 - x1) / 3);

    LineShape::Set(x1, y1, x1 - a, y1 + a);
	LineShape::Show(hdc);
	LineShape::Set(x2, y2, x2 - a, y2 + a);
	LineShape::Show(hdc);
	LineShape::Set(x1, y2, x1 - a, y2 + a);
	LineShape::Show(hdc);
	LineShape::Set(x2, y1, x2 - a, y1 + a);
	LineShape::Show(hdc);
	LineShape::Set(x1 - a, y1 + a, x2 - a, y1 + a);
	LineShape::Show(hdc);
	LineShape::Set(x2 - a, y1 + a, x2 - a, y2 + a);
	LineShape::Show(hdc);
	LineShape::Set(x2 - a, y2 + a, x1 - a, y2 + a);
	LineShape::Show(hdc);
	LineShape::Set(x1 - a, y2 + a, x1 - a, y1 + a);
	LineShape::Show(hdc);


	xs1 = x1; xs2 = x2; ys1 = y1; ys2 = y2;
}

void CubeShape::Editor(HDC hdc, int x1, int y1, int x2, int y2) {
	RecShape::Editor(hdc, x1, y1, x2, y2);

	a = abs((x2 - x1) / 3);

	LineShape::Editor(hdc, x1, y1, x1 - a, y1 + a);
	LineShape::Editor(hdc, x2, y2, x2 - a, y2 + a);
	LineShape::Editor(hdc, x1, y2, x1 - a, y2 + a);
	LineShape::Editor(hdc, x2, y1, x2 - a, y1 + a);
	LineShape::Editor(hdc, x1 - a, y1 + a, x2 - a, y1 + a);
	LineShape::Editor(hdc, x2 - a, y1 + a, x2 - a, y2 + a);
	LineShape::Editor(hdc, x2 - a, y2 + a, x1 - a, y2 + a);
	LineShape::Editor(hdc, x1 - a, y2 + a, x1 - a, y1 + a);

	xs1 = x1; xs2 = x2; ys1 = y1; ys2 = y2;
}