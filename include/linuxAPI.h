#pragma once

#include <iostream>
#include <X11/Xlib.h>

#define POSX 500
#define POSY 500

static Display* display;
static int screen;
static Window window;

// TODO: implement window creation with xlib (x11 gui api)
// should take dimensions, and a char* title
bool create_window(int width, int height, std::string title);

// TODO: implement window updating with xlib
// shouldn't take any arguments. The window should be passed globably.
void update_window();

void kill_window();