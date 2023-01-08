#include "matr_create.h"

void MatrixCreate::OnCopyData(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	COPYDATASTRUCT* cds;
	cds = (COPYDATASTRUCT*)lParam;
	int* data = (int*)cds->lpData;
	N = data[0];
	min = data[1];
	max = data[2];
	
	matrix = CreateMatrix(N, min, max);
	matrixText = GetMatrixString(matrix, N);

	PutToClipboard(hWnd, matrixText.c_str());

	InvalidateRect(hWnd, NULL, TRUE);
}

void MatrixCreate::OnPaint(HWND hWnd, HDC hdc) {
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	std::string sElem;
	std::wstring wsElem;
	double elem;

	int x = 10;
	int y = 10;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::stringstream ss;
			elem = matrix[i][j];
			ss << elem;
			ss >> sElem;
			wsElem = converter.from_bytes(sElem);
			TextOut(hdc, x, y, (LPCWSTR)wsElem.c_str(), (int)wcslen((LPCWSTR)wsElem.c_str()));

			x += 50;
		}
		x = 10;
		y += 35;
	}
}

int** MatrixCreate::CreateMatrix(int size, int minimum, int maximum) {
	int** result = new int* [size];
	for (int i = 0; i < size; i++)
		result[i] = new int[size];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(minimum, maximum);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			result[i][j] = dist(gen);

	return result;
}

std::string MatrixCreate::GetMatrixString(int** matrixSrc, int size) {
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	std::string result;
	std::ostringstream stream;
	int element;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			element = matrixSrc[i][j];
			stream << element << '\t';
		}
		stream << '\n';
	}
	result = stream.str();

	return result;
}

int MatrixCreate::PutToClipboard(HWND hWnd, const char* src) {
	HGLOBAL hglbCopy;
	BYTE* pTmp;
	long len;

	if (src == NULL) return 0;
	if (src[0] == 0) return 0;

	len = (long)strlen(src);
	hglbCopy = GlobalAlloc(GHND, len + 1);

	if (hglbCopy == NULL) return 0;

	pTmp = (BYTE*)GlobalLock(hglbCopy);
	memcpy(pTmp, src, len + 1);
	GlobalUnlock(hglbCopy);

	if (!OpenClipboard(hWnd)) {
		GlobalFree(hglbCopy);
		return 0;
	}

	EmptyClipboard();
	SetClipboardData(CF_TEXT, hglbCopy);
	CloseClipboard();

	return 1;
}