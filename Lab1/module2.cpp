#include "framework.h"
#include "module2_rh.h"

static INT_PTR CALLBACK Dlg2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDBACK) {
            EndDialog(hDlg, -1);
            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDOK) {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_Mod2(HWND hWnd, HINSTANCE hInst) {
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MOD2), hWnd, Dlg2);
}