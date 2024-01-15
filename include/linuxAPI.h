#pragma once

#include <iostream>
#include <X11/Xlib.h>

#define POSX 500
#define POSY 500

static Display* display;
static int screen;
static Window window;

/*
* Creates a window using the X11 API. The default values for position will be 
* 500x500, but the programmer can supply their own width, height and title for 
* the window.
* Currently, the only events it collects are KeyPresses
*/
bool create_window(int width, int height, std::string title);


/*
* This functions should be called every frame, it will look to see if an event
* has been trigger, and run other functions based on that
*/
void update_window();

/*
* This function closes the main window created with the X11 API
*/
void kill_window();