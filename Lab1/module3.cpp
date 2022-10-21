#include "framework.h"
#include "module3_rh.h"

WCHAR* textp;
TCHAR indx;

static INT_PTR CALLBACK Dlg3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        SendDlgItemMessage(hDlg, IDC_LIST_BOX, LB_ADDSTRING, 0, (LPARAM)L"²Ì-11");
        SendDlgItemMessage(hDlg, IDC_LIST_BOX, LB_ADDSTRING, 0, (LPARAM)L"²Ì-12");
        SendDlgItemMessage(hDlg, IDC_LIST_BOX, LB_ADDSTRING, 0, (LPARAM)L"²Ì-13");
        return (INT_PTR)TRUE;

    case WM_COMMAND:
            if (LOWORD(wParam) == IDOK) {
                indx = SendDlgItemMessage(hDlg, IDC_LIST_BOX, LB_GETCURSEL, 0, 0);
                SendDlgItemMessage(hDlg, IDC_LIST_BOX, LB_GETTEXT, indx, LPARAM(textp));
                EndDialog(hDlg, 1);
                return (INT_PTR)TRUE;
                break;
            }

            if (LOWORD(wParam) == IDCANCEL) {
                EndDialog(hDlg, 0);
                return (INT_PTR)TRUE;
                break;
            }
        default: break;
        }
        return (INT_PTR)FALSE;
 }


int Func_Mod3(HWND hWnd, HINSTANCE hInst, WCHAR* p) {
    textp = p;
    return DialogBox(hInst, MAKEINTRESOURCE(ID_DIALOG_MOD3), hWnd, Dlg3);
   }