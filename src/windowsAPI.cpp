#include <stdlib.h>

#include "windowsAPI.h"

HWND window;

LRESULT CALLBACK window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;

    switch (msg) {
        case WM_CLOSE: {
            exit(0);
            break;
        }
        default: {
            result = DefWindowProcA(window, msg, wParam, lParam);
        }
    }

    return result;
}

bool create_window(int width, int height, char* title) {
    HINSTANCE instance = GetModuleHandleA(0);
    WNDCLASS wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;
    wc.lpfnWndProc = window_callback; // TODO: fix window proc id

    if (!RegisterClassA(&wc)) {
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    window = CreateWindowExA(0,
                            title,
                            title,
                            dwStyle,
                            100,
                            100,
                            width,
                            height,
                            NULL,
                            NULL,
                            instance,
                            NULL
    );

    if (window == NULL) {
        return false;
    }

    ShowWindow(window, SW_SHOW);

    return true;
}

void update_window() {
    MSG msg;

    while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}