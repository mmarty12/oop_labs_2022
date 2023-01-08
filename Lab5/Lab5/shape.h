#pragma once
#include "framework.h"
#include <string>
#include <typeinfo>

class Shape
{
protected:
	long xstart = 0, ystart = 0, xend = 0, yend = 0;
public:
	void Set(long x1, long y1, long x2, long y2);
	void Show(HDC, bool);
	std::wstring getProperties();

	virtual Shape* New() = 0;
	virtual std::wstring getName() = 0;
	virtual void Draw(HDC) = 0;
	virtual void Editor(HDC) = 0;
	virtual LPCTSTR setWindowText() = 0;
};
