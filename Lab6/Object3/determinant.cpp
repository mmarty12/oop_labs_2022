#include "determinant.h"

void Determinant::OnCreate(HWND hWnd) {
	GetFromClipboard(hWnd, 10009);
	matrix = GetMatrix(matrixText);
	det = GetDet(matrix, N);

	InvalidateRect(hWnd, NULL, TRUE);
}

int Determinant::GetFromClipboard(HWND hWnd, long maxsize) {
	HGLOBAL hglb;
	LPTSTR lptstr;
	long size, res;
	res = 0;
	char* dest = new char[maxsize];
	if (!IsClipboardFormatAvailable(CF_TEXT)) return 0;
	if (!OpenClipboard(hWnd)) return 0;
	hglb = GetClipboardData(CF_TEXT);
	if (hglb != NULL)
	{
		lptstr = (LPTSTR)GlobalLock(hglb);
		if (lptstr != NULL)
		{
			size = (long)strlen((char*)lptstr);
			if (size > maxsize)
			{
				lptstr[maxsize] = 0;
				size = (long)strlen((char*)lptstr);
			}
			res = size;
			strcpy_s(dest, maxsize, (char*)lptstr);
			GlobalUnlock(hglb);
		}
	}
	CloseClipboard();
	matrixText = dest;

	return res;
}

int** Determinant::GetMatrix(std::string text) {
	std::stringstream stream(text);

	int size = (int)std::count(text.cbegin(), text.cend(), '\n');
	N = size;
	int** result = new int* [size];
	for (int i = 0; i < size; i++)
		result[i] = new int[size];

	int element;
	int i = 0;
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			stream >> element;
			result[i][j] = element;
		}
	}

	return result;
}

void Determinant::GetSubmatrix(int** src, int** dest, int N, int row, int col) {
	int di = 0;
	int dj = 0;

	int size = N - 1;
	for (int i = 0; i < size; i++)
	{
		if (i == row) di = 1;

		dj = 0;
		for (int j = 0; j < size; j++)
		{
			if (j == col) dj = 1;
			dest[i][j] = src[i + di][j + dj];
		}
	}
}

int Determinant::GetDet(int** matrix, int size) {
	int det = 0;
	int degree = 1;

	if (size == 1)
		return matrix[0][0];

	if (size == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	int** temp = new int* [size - 1];
	for (int i = 0; i < size - 1; i++)
		temp[i] = new int[size - 1];

	for (int j = 0; j < size; j++)
	{
		GetSubmatrix(matrix, temp, size, 0, j);
		det = det + (degree * matrix[0][j] * GetDet(temp, size - 1));
		degree = -degree;
	}

	for (int i = 0; i < size - 1; i++)
		delete[] temp[i];
	delete[] temp;

	return det;
}

void Determinant::OnPaint(HWND hWnd, HDC hdc) {
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	std::string sDet;
	std::wstring wsDet;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(0) << det;
	ss >> sDet;
	wsDet = converter.from_bytes(sDet);

	TextOut(hdc, 50, 50, (LPCWSTR)wsDet.c_str(), (int)wcslen((LPCWSTR)wsDet.c_str()));
}