#pragma once
#include "framework.h"
#include "resource1.h"
#include <string>
#include <cmath>

class MatrixDialog {
private:
	MatrixDialog() {}
	MatrixDialog(const MatrixDialog& root) = delete;
	MatrixDialog& operator = (const MatrixDialog&) = delete;
public:
	static MatrixDialog& getInstance()
	{
		static MatrixDialog instance;
		return instance;
	}

	static std::wstring GetBoxText(HWND, int);
	static void SendData(HWND, HWND, void*, long);

	void Start(HINSTANCE, HWND);
	void End();
};