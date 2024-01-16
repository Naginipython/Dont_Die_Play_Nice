#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>

/*
Callback for win32 window, allows for recieving input and closing terminating script by closing window
*/
LRESULT CALLBACK window_callback(HWND win, UINT msg, WPARAM wParam, LPARAM lParam, bool* running);