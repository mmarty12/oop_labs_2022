#include "my_editor.h"


MyEditor* MyEditor::p_instance = 0;
MyEditor* MyEditor::getInstance()
{
	if (!p_instance)
		p_instance = new MyEditor();
	return p_instance;
}

void MyEditor::Start(Shape* shape, HWND hWnd, UINT toolID, UINT menuID, LPARAM lParam)
{
	parentShape = shape;
	ToolBar.OnTool(hWnd, lParam);
	SetWindowText(hWnd, parentShape->setWindowText());
}

void MyEditor::OnLBdown(HWND hWnd)
{
	if (parentShape)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xstart = pt.x;
		ystart = pt.y;

		pshape[i] = parentShape->New();
		pshape[i]->Set(xstart, ystart, xend, yend);
	}
}

std::wstring MyEditor::OnLBup(HWND hWnd)
{
	std::wstring properties = L"";

	if (xstart)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xend = pt.x;
		yend = pt.y;

		pshape[i]->Set(xstart, ystart, xend, yend);
		properties = pshape[i]->getProperties();
		if (i < ARRAY_SIZE - 1) i++;
		else i = 0;

		xstart = 0, ystart = 0, xend = 0, yend = 0;

		InvalidateRect(hWnd, NULL, TRUE);
	}

	return properties;
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (xstart)
	{
		POINT pt;
		HPEN hPen = CreatePen(PS_DOT, 1, 0);
		HDC hdc = GetDC(hWnd);
		HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

		SetROP2(hdc, R2_NOTXORPEN);

		if (xend) pshape[i]->Editor(hdc);

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;

		pshape[i]->Set(xstart, ystart, xend, yend);
		pshape[i]->Editor(hdc);

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}

void MyEditor::OnPaint(HWND hWnd, int selectedItem)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < ARRAY_SIZE; i++)
		if (pshape[i])
		{
			bool isSelected = selectedItem == i ? true : false;
			pshape[i]->Show(hdc, isSelected);
		}
	EndPaint(hWnd, &ps);
}


void MyEditor::RemoveItem(int selectedItem)
{
	if (selectedItem >= 0)
	{
		for (int i = 0; i < ARRAY_SIZE; i++)
			if (i >= selectedItem)
			{
				Shape* next = pshape[i + 1];
				if (next)
					pshape[i] = next;
				else
				{
					pshape[i] = NULL;
					break;
				}
			}
		i--;
	}
}

void MyEditor::OnCreate(HWND hWnd, HINSTANCE hInst)
{
	ToolBar.OnCreate(hWnd, hInst);
}

void MyEditor::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ToolBar.OnNotify(hWnd, wParam, lParam);
}

void MyEditor::OnSize(HWND hWnd)
{
    ToolBar.OnSize(hWnd);
}