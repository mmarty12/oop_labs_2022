#pragma once
#pragma comment(lib, "comctl32.lib")

class ToolBar {
protected:
	HWND hwndToolBar = NULL;
	LPARAM oldlParam = NULL;
public:
	ToolBar(void);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnTool(HWND, LPARAM);
	void OnNotify(HWND, WPARAM, LPARAM);
};