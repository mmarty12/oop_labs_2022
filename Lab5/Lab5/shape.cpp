#include "shape.h"

void Shape::Set(long x1, long y1, long x2, long y2)
{
	xstart = x1;
	ystart = y1;
	xend = x2;
	yend = y2;
}

void Shape::Show(HDC hdc, bool isSelected)
{
	COLORREF color = isSelected ? 0x0000ff : 0;

	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

	Draw(hdc);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

std::wstring Shape::getProperties()
{
	WCHAR properties[50];
	const wchar_t* format;
	
	std::wstring name = getName();
	if (name.length() > 8)
		format = L"%s\t%d\t%d\t%d\t%d";
	else
		format = L"%s\t\t%d\t%d\t%d\t%d";

	swprintf_s(properties, 50, format, name.c_str(), xstart, ystart, xend, yend);
	return properties;
}