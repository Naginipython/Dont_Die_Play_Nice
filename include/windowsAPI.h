#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>


HWND window;

LRESULT CALLBACK window_callback(HWND win, UINT msg, WPARAM wParam, LPARAM lParam);

bool create_window(int width, int height, char* title);

void update_window();