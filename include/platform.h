#pragma once

/*
* Creates a window using your platform's API. One can supply their own width, 
* height and title for the window.
* Currently, the only events it collects are KeyPresses
*/
bool create_window(int width, int height, std::string title);

/*
* This functions should be called every frame, it will look to see if an event
* has been trigger, and run other functions based on that
*/
void update_window();

void* platform_load_gl_function(char* funName);

#if __WIN32
    #include "windowsAPI.h"
    #define WIN32_LEAN_AND_MEAN
    #define NOMINMAX
    #include <windows.h>

    HWND window;

    LRESULT CALLBACK window_callback(HWND win, UINT msg, WPARAM wParam, LPARAM lParam);
    // int os = 0;
#elif __linux__
    #include <X11/Xlib.h>

    #define POSX 500
    #define POSY 500

    static Display* display;
    static int screen;
    static Window window;

    /*
    * This function closes the main window created with the X11 API
    */
    void kill_window();

    // int os = 1;
#else
    // int os = 2;
#endif