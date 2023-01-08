#pragma once
#include "framework.h"
#include <string>
#include <random>
#include <sstream>
#include <codecvt>

class MatrixCreate {
private:
	MatrixCreate() {}
	MatrixCreate(const MatrixCreate& root) = delete;
	MatrixCreate& operator = (const MatrixCreate&) = delete;

	int N = 0;
	int min = 0;
	int max = 0;

	int** matrix = 0;
	std::string matrixText = "";
public:
	static MatrixCreate& getInstance()
	{
		static MatrixCreate instance;
		return instance;
	}

	void OnCopyData(HWND, WPARAM, LPARAM);
	void OnPaint(HWND, HDC);
	int** CreateMatrix(int, int, int);
	std::string GetMatrixString(int**, int);
	int PutToClipboard(HWND, const char*);
};