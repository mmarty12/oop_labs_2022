#include "my_table.h"

HWND MyTable::hWndTable = NULL;
HWND MyTable::hWndParent = NULL;

LPCSTR MyTable::path = "objects_table.txt";
int MyTable::selectedItem = 0;
int MyTable::toRemove = 0;

INT_PTR CALLBACK Table(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		WORD button = LOWORD(wParam);
		WORD action = HIWORD(wParam);

		if (button == IDEXIT || button == IDCANCEL)
		{
			MyTable::setSelected(0);
			InvalidateRect(MyTable::getParent(), NULL, TRUE);

			ShowWindow(MyTable::getTable(), SW_HIDE);
			return (INT_PTR)TRUE;
		}

		if (action == LBN_SELCHANGE)
		{
			int selectedItem = (int)SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);
			MyTable::setSelected(selectedItem);
		}

		if (action == LBN_DBLCLK)
		{
			int selectedItem = (int)SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);

			if (selectedItem)
			{
				MyTable::Remove(selectedItem);
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_DELETESTRING, selectedItem, 0);
			}
		}
		InvalidateRect(MyTable::getParent(), NULL, TRUE);
		break;
	}
	return (INT_PTR)FALSE;
}


HWND MyTable::getTable()
{
	return hWndTable;
}

HWND MyTable::getParent()
{
	return hWndParent;
}


void MyTable::setSelected(int number)
{
	selectedItem = number;
}

int MyTable::getSelected()
{
	return selectedItem;
}

void MyTable::setRemove(int number)
{
	toRemove = number;
}

int MyTable::getRemove()
{
	return toRemove;
}

void MyTable::OnCreate(HWND hWnd, HINSTANCE hInst)
{
	FILE* fout;
	fopen_s(&fout, path, "wt");
	if (fout)
	{
		fprintf(fout, "");
		fclose(fout);
	}

	hWndParent = hWnd;
	hWndTable = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TABLE), 0, Table);
	ShowWindow(hWndTable, SW_HIDE);

	std::wstring title = L"Фігура\t\tx1\ty1\tx2\ty2";
	Add(title);
}

void MyTable::Show()
{
	ShowWindow(hWndTable, SW_SHOW);
}

void MyTable::Add(std::wstring properties)
{
	if (properties != L"")
	{
		using convert_type = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_type, wchar_t> converter;

		std::ofstream file;
		file.open(path, std::ofstream::app);
		if (file.is_open())
			file << converter.to_bytes(properties) << std::endl;
		file.close();

		SendMessage(GetDlgItem(hWndTable, IDC_LIST1), LB_ADDSTRING, 0, (LPARAM)properties.c_str());
	}
}

void MyTable::Remove(int selectedItem)
{
	std::ifstream filein;
	filein.open(path);

	std::string line;
	std::string table;

	int i = 0;
	while (getline(filein, line))
	{
		if (i != selectedItem)
		{
			table.insert(table.size(), line);
			table.insert(table.size(), "\n");
		}
		i++;
	}

	filein.close();

	std::ofstream fileout;
	fileout.open(path);
	fileout << table << std::endl;
	fileout.close();

	setRemove(selectedItem);
	setSelected(0);
}