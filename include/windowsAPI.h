#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

bool win32_create_window(int width, int height, char* title) {
    HINSTANCE instance = GetModuleHandleA(0);
    WNDCLASS wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title;
    wc.lpfnWndProc = DefWindowProcA; // TODO: fix window proc id

    if (!RegisterClassA(&wc)) {
        return false;
    }

    int dwStyle = WS_OVERLAPPEDWINDOW;

    HWND window = CreateWindowExA(0,
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

#endif