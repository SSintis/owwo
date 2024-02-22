#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "SoftwearDefinitions.h"
#include "resource.h"
using namespace std;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)GetStockObject(WHITE_BRUSH), LoadCursor(NULL, IDC_ARROW), hInstance,
		LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)),L"MainWndClass", WndProc);

	if (!RegisterClassW(&SoftwareMainClass)) return -1;
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(L"MainWndClass", L"Slava", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 200, 500, 250, NULL, NULL, NULL, NULL);
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC WndProc) {
	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = WndProc;

	return NWC;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
		switch (wParam) {
		case OnMenuAction1:
			MessageBoxA(hWnd, "Menu '1' was clicked!", "Menu worked", MB_OK);
			break;

		case OnMenuAction2:
			MessageBoxA(hWnd, "Menu '2' was clicked!", "Menu worked", MB_OK);
			break;

		case OnMenuAction3:
			MessageBoxA(hWnd, "Menu '3' was clicked!", "Menu worked", MB_OK);
			break;

		case OnClearField:
			SetWindowTextA(hEditControl, "");
			break;

		case OnMenuExit:
			PostQuitMessage(0);
			break;
		default:break;
		}
		break;

	case WM_CREATE:
		MainWndAddMenus(hWnd); 
		MainWndAddWidgets(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

void MainWndAddMenus(HWND hWnd) {
	HMENU RootMenu = CreateMenu();
	HMENU SubMenu = CreateMenu();
	HMENU SubMenuAction = CreateMenu();

	AppendMenu(SubMenu, MF_STRING, OnClearField, L"Clear");

	AppendMenu(SubMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenu, MF_STRING, OnMenuExit, L"Exit");

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"Menu");
	AppendMenu(RootMenu, MF_STRING, (UINT_PTR)SubMenu, L"Help");

	SetMenu(hWnd, RootMenu);
}

void MainWndAddWidgets(HWND hWnd) {
	CreateWindowA("static", "STATUS: Hello Window!", WS_VISIBLE | WS_CHILD | ES_CENTER, 140, 5, 350, 30, hWnd, NULL, NULL, NULL);

	hEditControl = CreateWindowA("edit", "Хэллоу мир манера крутит мир!", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 40, 470, 100, hWnd, NULL, NULL, NULL);

	CreateWindowA("button", "Clear", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 120, 30, hWnd, (HMENU)OnClearField, NULL, NULL);
}