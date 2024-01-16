#pragma once

#include <iostream>
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