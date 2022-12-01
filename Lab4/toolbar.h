#pragma once
#pragma comment(lib, "comctl32.lib")

class ToolBar {
protected:
	HWND hWndToolbar = NULL;
	LPARAM oldLParam = NULL;
public:
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnPressBtn(HWND, LPARAM);
};