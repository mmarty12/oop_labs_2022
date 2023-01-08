#include "matr_dialogWind.h"

INT_PTR CALLBACK Matrix(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            int N = 0;
            int min = 0;
            int max = 0;

            try
            {
                N = (int)round(stod(MatrixDialog::GetBoxText(hDlg, IDC_N)));
                min = (int)round(stod(MatrixDialog::GetBoxText(hDlg, IDC_MIN)));
                max = (int)round(stod(MatrixDialog::GetBoxText(hDlg, IDC_MAX)));
            }
            catch (...)
            {
                MessageBox(hDlg, L"Неправильний формат", L"ERROR", MB_OK | MB_ICONERROR);
                break;
            }

            if (min > max || N < 1 || N > 10 || abs(min) > 99999 || abs(max) > 99999)
            {
                MessageBox(hDlg, L"Введено некоректні дані", L"ERROR", MB_OK | MB_ICONERROR);
                break;
            }

            HWND hWnd2 = FindWindow(L"OBJECT2", NULL);
            if (!hWnd2)
            {
                WinExec("Object2.exe", SW_SHOW);
                hWnd2 = FindWindow(L"OBJECT2", NULL);
            }
            
            int data[3] = { N, min, max };
            MatrixDialog::SendData(hWnd2, GetParent(hDlg), data, sizeof(data));

            HWND hWnd3 = FindWindow(L"OBJECT3", NULL);
            if (!hWnd3)
            {
                WinExec("Object3.exe", SW_SHOW);
                hWnd3 = FindWindow(L"OBJECT3", NULL);
            }
            PostMessage(hWnd3, WM_CLIPBOARDUPDATE, NULL, NULL);

            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


std::wstring MatrixDialog::GetBoxText(HWND hWnd, int boxID)
{
    WCHAR buff[7];
    GetWindowText(GetDlgItem(hWnd, boxID), buff, 7);

    return buff;
}

void MatrixDialog::SendData(HWND hWndDest, HWND hWndSrc, void* lp, long cb)
{
    COPYDATASTRUCT cds;

    cds.dwData = 1;
    cds.cbData = cb;
    cds.lpData = lp;

    SendMessage(hWndDest, WM_COPYDATA, (WPARAM)hWndSrc, (LPARAM)&cds);
}

void MatrixDialog::Start(HINSTANCE hInst, HWND hWnd)
{
    DialogBox(hInst, MAKEINTRESOURCE(IDD_MATRIX), hWnd, Matrix);
}

void MatrixDialog::End()
{
    HWND hWnd2 = FindWindow(L"OBJECT2", NULL);
    HWND hWnd3 = FindWindow(L"OBJECT3", NULL);

    if (hWnd2) PostMessage(hWnd2, WM_DESTROY, NULL, NULL);
    if (hWnd3) PostMessage(hWnd3, WM_DESTROY, NULL, NULL);
}