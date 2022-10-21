#include "framework.h"
#include "module1_rh.h"

static INT_PTR CALLBACK Dlg1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDNEXT) {
            EndDialog(hDlg, 1);
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

int Func_Mod1(HWND hWnd, HINSTANCE hInst) {
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MOD1), hWnd, Dlg1);
}