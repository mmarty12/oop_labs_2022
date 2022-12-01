#include "framework.h"
#include "lineOOShape.h"
#include "resource.h"

Shape* LineOOShape::New() {
	return new LineOOShape;
}

void LineOOShape::Show(HDC hdc) {
	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1, y1, x2, y2);
	LineShape::Show(hdc);

	EllipseShape::Set(x1 - 20, y1 - 20, x1 + 20, y1 + 20);
	EllipseShape::Show(hdc);

	EllipseShape::Set(x2 - 20, y2 - 20, x2 + 20, y2 + 20);
	EllipseShape::Show(hdc);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

void LineOOShape::Editor(HDC hdc, int x1, int y1, int x2, int y2) {
	a = abs(x2 - x1) > abs(y2 - y1) ? abs(x2 - x1) / 5 : abs(y2 - y1) / 5;

	LineShape::Editor(hdc, x1, y1, x2, y2);
	EllipseShape::Editor(hdc, x1 - a, y1 - a, x1 + a, y1 + a);
	EllipseShape::Editor(hdc, x2 + a, y2 + a, x2 - a, y2 - a);

	xs1 = x1; xs2 = x2; ys1 = y1; ys2 = y2;
}