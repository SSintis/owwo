#pragma once
#define OnMenuAction1	1
#define OnMenuAction2	2
#define OnMenuAction3	3
#define OnMenuExit		4
#define OnClearField	5

HWND hEditControl;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC WndProc);

void MainWndAddMenus(HWND hWnd);
void MainWndAddWidgets(HWND hWnd);