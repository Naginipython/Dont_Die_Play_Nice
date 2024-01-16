#include "platform.h"

bool create_window(int width, int height, std::string title) {
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

    window = CreateWindowExA(0,
                            title.c_str(),
                            title.c_str(),
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

void* platform_load_gl_function(char* funName) {
    PROC proc = wglGetProcAddress(funName);
    if (!proc) {
        static HMODULE openglDLL = LoadLibraryA("opengl32.dll");
        proc = wglGetProcAddress(openglDLL, funName);
        if (!proc) {
            SM_ASSERT(false, "Failed to load gl functions %s", "glCreatreProgram");
            return nullptr;
        }
    }
    return (void*) proc;
}