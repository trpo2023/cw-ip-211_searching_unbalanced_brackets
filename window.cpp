#include <Windows.h>
#include <string>
#include "SD.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

    WNDCLASS CodMainClass = NewWC((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_HAND), hInst, LoadIcon(NULL, IDI_QUESTION), L"CodMainC", CodMainPr);

    if (!RegisterClassW(&CodMainClass)) { return -1; }
    MSG SMM = { 0 };

    CreateWindow(L"CodMainC", L"MW", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 800, 500, NULL, NULL, NULL, NULL);
    while (GetMessage(&SMM, NULL, NULL, NULL)) {
        TranslateMessage(&SMM);
        DispatchMessage(&SMM);
    }
    return 0;
}

WNDCLASS NewWC(HBRUSH bcolor, HCURSOR cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedur) {

    WNDCLASS NWC = { 0 };

    NWC.hIcon = Icon;
    NWC.hCursor = cursor;
    NWC.hInstance = hInst;
    NWC.lpszClassName = Name;
    NWC.hbrBackground = bcolor;
    NWC.lpfnWndProc = Procedur;

    return NWC;

}

LRESULT CALLBACK CodMainPr(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_COMMAND:
        switch (wp) {
        case OnButtonClicked1:
            //UW(hWnd);
            //InvalidateRect(hWnd, NULL, TRUE);
            //UpdateWindow(hWnd);
            break;
        case OnButtonClicked2:
            PostQuitMessage(0);
            break;
        case OnButtonClicked3:
            PostQuitMessage(0);
            break;
        case OnButtonClicked4:
            PostQuitMessage(0);
            break;
        default: break;
        }
    case WM_CREATE:
        MWAW(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default: return DefWindowProc(hWnd, msg, wp, lp);
    }
}

void MWAW(HWND hWnd) {

    CreateWindowA("static", "Выбирите один из вариантов", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 490, 20, hWnd, NULL, NULL, NULL);

    CreateWindowA("button", " Выбор файла ", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 30, 120, 20, hWnd, (HMENU)OnButtonClicked1, NULL, NULL);
    CreateWindowA("button", " Выбор из папки ", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 60, 120, 20, hWnd, (HMENU)OnButtonClicked2, NULL, NULL);
    CreateWindowA("button", " Ввод програмы в окно ", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 90, 160, 20, hWnd, (HMENU)OnButtonClicked3, NULL, NULL);
    CreateWindowA("button", " выход ", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 120, 160, 20, hWnd, (HMENU)OnButtonClicked4, NULL, NULL);

}

void UW(HWND hWnd) {
    RECT rect;
    GetClientRect(hWnd, &rect);
    HDC hdc = GetDC(hWnd);
    HDC hMemDC = CreateCompatibleDC(hdc);
    HBITMAP hwindbm = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
    DeleteObject(SelectObject(hMemDC, hwindbm));
}