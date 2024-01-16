#pragma once

#if __WIN32
    #include "WindowsAPI.h"
#elif __linux__
    #include "LinuxAPI.h"
#endif

/*
* Creates a window using the platform's API. The default values for position will be 
* 500x500, but a custom width, height and title for the window can be supplied.
*
* Currently, the only events it collects are KeyPresses (Linux)
*/
bool create_window(int width, int height, char* title);

/*
* This functions should be called every frame, it will look to see if an event
* has been trigger, and run other functions based on that
*/
void update_window();