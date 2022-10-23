#include "framework.h"
#include "recShape.h"

void RecShape::Show(HDC hdc) {
    MoveToEx(hdc,xs1,ys1,NULL);
    LineTo(hdc,xs1,ys2);
    MoveToEx(hdc, xs1, ys2, NULL);
    LineTo(hdc, xs2, ys2);
    MoveToEx(hdc, xs2, ys2, NULL);
    LineTo(hdc, xs2, ys1);
    MoveToEx(hdc, xs2, ys1, NULL);
    LineTo(hdc, xs1, ys1);
};