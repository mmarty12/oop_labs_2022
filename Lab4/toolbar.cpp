#include "framework.h"
#include "Resource.h"
#include "resource1.h"
#include "toolbar.h"
#include <commctrl.h>

void ToolBar::OnCreate(HWND hWnd, HINSTANCE hInst) {
	TBBUTTON tbb[6]; //����� ����� ������ ���� Toolbar
	ZeroMemory(tbb, sizeof(tbb));

	tbb[0].iBitmap = 0; //���������� ����������
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON; //��� �������� - ������
	tbb[0].idCommand = ID_TOOL_POINT; //��� ID ���� � ���������� WM_COMMAND

	tbb[1].iBitmap = 1;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = ID_TOOL_LINE;

	tbb[2].iBitmap = 2;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = ID_TOOL_REC;

	tbb[3].iBitmap = 3;
	tbb[3].fsState = TBSTATE_ENABLED;
	tbb[3].fsStyle = TBSTYLE_BUTTON;
	tbb[3].idCommand = ID_TOOL_ELLIPSE;

	tbb[4].iBitmap = 4;
	tbb[4].fsState = TBSTATE_ENABLED;
	tbb[4].fsStyle = TBSTYLE_BUTTON;
	tbb[4].idCommand = ID_TOOL_CUBE;

	tbb[5].iBitmap = 5;
	tbb[5].fsState = TBSTATE_ENABLED;
	tbb[5].fsStyle = TBSTYLE_BUTTON;
	tbb[5].idCommand = ID_TOOL_LINEOO;

	hWndToolbar = CreateToolbarEx(hWnd, //���������� ����
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP |
		TBSTYLE_TOOLTIPS,
		IDC_MY_TOOLBAR, //ID ���������� ���� Toolbar
		6, hInst, IDB_TOOLBAR,
		tbb,
		6, //������� ������
		24, 24, 24, 24, //������������ �� ������
		sizeof(TBBUTTON));
};

void ToolBar::OnSize(HWND hWnd) {
	RECT rc, rw;
	if (hWndToolbar)
	{
		GetClientRect(hWnd, &rc); //��� ������ ��������� ����
		GetWindowRect(hWndToolbar, &rw); //��� ������� ����� ������ Toolbar
		MoveWindow(hWndToolbar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
	}
};

void ToolBar::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	LPNMHDR pnmh = (LPNMHDR)lParam;
	if (pnmh->code == TTN_NEEDTEXT)
	{
		LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
		switch (lpttt->hdr.idFrom)
		{
		case ID_TOOL_POINT:
			lstrcpy(lpttt->szText, L"������");
			break;
		case ID_TOOL_LINE:
			lstrcpy(lpttt->szText, L"˳��");
			break;
		case ID_TOOL_REC:
			lstrcpy(lpttt->szText, L"�����������");
			break;
		case ID_TOOL_ELLIPSE:
			lstrcpy(lpttt->szText, L"����");
			break;
		case ID_TOOL_CUBE:
			lstrcpy(lpttt->szText, L"���");
			break;
		case ID_TOOL_LINEOO:
			lstrcpy(lpttt->szText, L"˳�� � ����������");
			break;
		};
	};
};

void ToolBar::OnPressBtn(HWND hWnd, LPARAM lParam) {
	if (oldLParam)
	{
		SendMessage(hWndToolbar, TB_PRESSBUTTON, oldLParam, 0);
	}
	SendMessage(hWndToolbar, TB_PRESSBUTTON, lParam, 1);
	oldLParam = lParam;
};